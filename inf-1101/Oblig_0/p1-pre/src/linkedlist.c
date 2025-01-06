/**
 * @authors
 * Steffen Viken Valvaag
 * Odin Bjerke <odin.bjerke@uit.no>
 */

#include "list.h"
#include "printing.h"

#include <stdlib.h>


typedef struct lnode lnode_t;
struct lnode {
    lnode_t *next;
    lnode_t *prev;
    void *item;
};

struct list {
    lnode_t *head;
    lnode_t *tail;
    size_t length;
    cmp_fn cmpfn;
};

struct list_iter {
    list_t *list;
    lnode_t *node;
};



list_t *list_create(cmp_fn cmpfn) {
    list_t *newList = malloc(sizeof(list_t));

    if (newList == NULL){
        printf("Malloc failed %d", __LINE__);
        return NULL;
    }

    newList->head = NULL;
    newList->tail = NULL;
    newList->length = 0;
    newList->cmpfn = cmpfn;
    return newList;
}

void list_destroy(list_t *list, free_fn item_free) {
    lnode_t *temp = list->head;
    lnode_t *prev = NULL;

    while (temp != NULL){
        prev = temp;
        temp = temp->next;
        free(prev);
    }
    free(list);
}

size_t list_length(list_t *list) {
    return list->length;
}

int list_addfirst(list_t *list, void *item) {
    lnode_t *newNode = malloc(sizeof(lnode_t));

    if (newNode == NULL){
        printf("Malloc failed %d", __LINE__);
        return -1;
    }

    newNode->item = item;
    
    newNode->next = list->head;

    if (list->head != NULL){
        list->head->prev = newNode;
    }
    list->length += 1;
    return 0;
}

int list_addlast(list_t *list, void *item) {
    lnode_t *newNode = malloc(sizeof(lnode_t));

    if (newNode == NULL){
        printf("Malloc failed %d", __LINE__);
        return -1;
    }

    newNode->item = item;

    lnode_t *temp = list->head;

    if (temp == NULL){   // if empty list
        list->head = newNode;
        newNode->next = NULL;
        return 0;
    }

    while (temp != NULL) {
        if (temp->next == NULL){
            temp->next = newNode;
            newNode->next = NULL;
            newNode->prev = temp;
            list->length += 1;
            return 0;
        }
        temp = temp->next;
    }
}

void *list_popfirst(list_t *list) { // memory leak fix pls
    if (list->head == NULL){
        printf(stderr, "PANIC PANIC, list empty: file: %s line: %d\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    lnode_t *popped = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    return popped->item;
}

void *list_poplast(list_t *list) {
    if (list->head == NULL){
        printf(stderr, "PANIC PANIC, list empty: file: %s line: %d\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    lnode_t *temp = list->head;
    lnode_t *prev = NULL;

    while (temp != NULL){
        if (temp->next == NULL){
            prev->next = NULL;
            return temp->item;
        }
    }
}

int list_contains(list_t *list, void *item) {
    lnode_t *temp = list->head; 

    while (temp != NULL)
    {
        if (temp->item == item){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}


/* ---- list iterator ---- */

list_iter_t *list_createiter(list_t *list) {
    list_iter_t *iter = malloc(sizeof(list_iter_t));

    if (iter == NULL){
        printf("Malloc failed %d", __LINE__);
        return NULL;
    }

    iter->node = NULL;
    iter->list = list;
    return iter;
}

void list_destroyiter(list_iter_t *iter) {
    free(iter);
}

int list_hasnext(list_iter_t *iter) {
    if (iter->node->next == NULL){
        return 0;
    }
    return 1;
}

void *list_next(list_iter_t *iter) {

}

void list_resetiter(list_iter_t *iter) {

}



/* ---- mergesort: Steffen Viken Valvaag ---- */

/*
 * Merges two sorted lists a and b using the given comparison function.
 * Only assigns the next pointers; the prev pointers will have to be
 * fixed by the caller.  Returns the head of the merged list.
 */
static lnode_t *merge(lnode_t *a, lnode_t *b, cmp_fn cmpfn) {
    lnode_t *head, *tail;

    /* Pick the smallest head node */
    if (cmpfn(a->item, b->item) < 0) {
        head = tail = a;
        a = a->next;
    } else {
        head = tail = b;
        b = b->next;
    }

    /* Now repeatedly pick the smallest head node */
    while (a && b) {
        if (cmpfn(a->item, b->item) < 0) {
            tail->next = a;
            tail = a;
            a = a->next;
        } else {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }

    /* Append the remaining non-empty list (if any) */
    if (a) {
        tail->next = a;
    } else {
        tail->next = b;
    }

    return head;
}

/**
 * Splits the given list in two halves, and returns the head of
 * the second half.
 */
static lnode_t *splitlist(lnode_t *head) {
    /* Move two pointers, a 'slow' one and a 'fast' one which moves
     * twice as fast.  When the fast one reaches the end of the list,
     * the slow one will be at the middle.
     */
    lnode_t *slow = head;
    lnode_t *fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Now 'cut' the list and return the second half */
    lnode_t *half = slow->next;
    slow->next = NULL;

    return half;
}

/**
 * Recursive merge sort.  This function is named mergesort_ to avoid
 * collision with the mergesort function that is defined by the standard
 * library on some platforms.
 */
static lnode_t *mergesort_(lnode_t *head, cmp_fn cmpfn) {
    if (head->next == NULL) {
        return head;
    }

    lnode_t *half = splitlist(head);
    head = mergesort_(head, cmpfn);
    half = mergesort_(half, cmpfn);

    return merge(head, half, cmpfn);
}

void list_sort(list_t *list) {
    /* Recursively sort the list */
    list->head = mergesort_(list->head, list->cmpfn);

    // /* Fix the tail and prev links */
    // lnode_t *prev = NULL;
    // for (lnode_t *n = list->head; n != NULL; n = n->next) {
    //     n->prev = prev;
    //     prev = n;
    // }
    // list->tail = prev;
}
