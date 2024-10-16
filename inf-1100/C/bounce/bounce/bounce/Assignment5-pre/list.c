#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
 * List implementation
 */

typedef struct listnode listnode_t;

struct listnode {
    listnode_t  *next;
    void        *item;
};

struct list {
    listnode_t *head;
    int numitems;
};

// struct for list iterator
struct list_iterator{
    listnode_t *current;
    list_t *list;
};

// creates an empty list
list_t *list_create(void){
    list_t *newList = (list_t*)malloc(sizeof(list_t));

    // handles malloc failure
    if (newList == NULL){ 
        printf("malloc failed %d", __LINE__);
        return NULL;
    }

    newList->head = NULL;
    newList->numitems = 0;
    return newList;
}

// function to destroy list
void list_destroy(list_t *list){
    listnode_t *temp = list->head;
    listnode_t *prev = NULL;
    
    // frees the previous node, but not the item
    while (temp != NULL){
        prev = temp;
        temp = temp->next;
        free(prev);
    }
    free(list);    //deletes the last node, but not the item
}

// function to add a node to the front of the list
void list_addfirst(list_t *list, void *item){
    // create node
    listnode_t *newNode = (listnode_t*)malloc(sizeof(listnode_t));  // allocates memory for the new node

    if (newNode == NULL){   // handles malloc failure
        printf("malloc failed %d", __LINE__);
        return;
    }
    // gives newNode its value
    newNode->item = item;

    // sets newNode as the first elementet in the linked list
    newNode->next = list->head; 
    list->head = newNode;
    list->numitems = list->numitems + 1;
}

// function to add a node to the end of the list
void list_addlast(list_t *list, void *item){
    // create node
    listnode_t *newNode = (listnode_t*)malloc(sizeof(listnode_t));
    
    // handles malloc failure
    if (newNode == NULL){   
        printf("malloc failed %d", __LINE__);
        return;
    }
    newNode->item = item;

    listnode_t *temp = list->head;

    // if empty list
    if (temp == NULL){
        list->head = newNode;
        newNode->next = NULL;
        list->numitems = list->numitems + 1;
        return;
    }

    while (temp != NULL){
        if (temp->next == NULL){
            //places newNode after the last element
            temp->next = newNode;
            newNode->next = NULL;
            list->numitems = list->numitems + 1;
            return;
        }
        temp = temp->next;
    }
}

// function to remove an element from the list
void list_remove(list_t *list, void *item) {
    listnode_t *temp = list->head;
    listnode_t *prev = NULL;

    // Iterates through the list
    while (temp != NULL) {
        if (temp->item == item) {
            if (prev == NULL) {  // If it's the first item
                list->head = temp->next;
                
            } else {
                prev->next = temp->next;
            }
            
            list->numitems = list->numitems - 1;
            // here we have a small memory leak but when we try to free head we get a seg fault
            return;  // Stop after removal
        }
        prev = temp;
        temp = temp->next;
    }
}

// function to check the length of the list
int list_size(list_t *list){
    return list->numitems;
}

// function to create list iterator
list_iterator_t *list_createiterator(list_t *list){
    list_iterator_t *iter = (list_iterator_t*)malloc(sizeof(list_iterator_t));
    
    if (iter == NULL){   // handles malloc failure
        printf("malloc failed %d", __LINE__);
        return NULL;
    }

    iter->current = NULL;     
    iter->list = list;
    return iter;
}

// function to destroy list iterator
void list_destroyiterator(list_iterator_t *iter){
    free(iter);
}

// function to go to the next element in the list
void *list_next(list_iterator_t *iter){
    // if start of list
    if (iter->current == NULL){
        iter->current = iter->list->head;
        return iter->current->item;
    }

    if (iter->current->next != NULL){
        iter->current = iter->current->next; 
        return iter->current->item;
        
    }  
    // if end of list 
    return NULL;
}

// function to reset the iterator 
void list_resetiterator(list_iterator_t *iter){
    iter->current = NULL;
}