board = [[0, 4, 0, 1, 0, 0, 0, 5, 0], 
         [1, 0, 7, 0, 0, 3, 9, 6, 0], 
         [5, 2, 0, 0, 0, 8, 0, 0, 0], 
         [0, 0, 0, 0, 0, 0, 0, 1, 7], 
         [0, 0, 0, 9, 0, 6, 8, 0, 0], 
         [8, 0, 3, 0, 5, 0, 6, 2, 0], 
         [0, 9, 0, 0, 6, 0, 5, 4, 3], 
         [6, 0, 0, 0, 8, 0, 7, 0, 0], 
         [2, 5, 0, 0, 9, 7, 1, 0, 0]]

for i in board:
    print(i)

print("\n")

for i in range(len(board)):
    print([board[j][i] for j in range(len(board))])

print("\n")


for i in range(0, 9, 3):    # (0, 3, 9) 
    for j in range(0, 9, 3):
        print([board[row][col] for row in range(i, i + 3) for col in range(j, j + 3)])