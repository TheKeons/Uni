from sudoku_reader import Sudoku_reader

class Board:
    # It is your task to subclass this in order to make it more fit
    # to be a sudoku board

    def __init__(self, nums):
        # Nums parameter is a 2D list, like what the sudoku_reader returns
        self.n_rows = len(nums[0])
        self.n_cols = len(nums)
        self.nums = [[None for _ in range(self.n_rows)] for _ in range(self.n_cols)]

    def _set_up_nums(self):
        # Set up the squares on the board (ints into Square objects)
        pass

    def _set_up_elems(self):
        # You should set up links between your squares and elements
        # (rows, columns, boxes)
        pass

    def solve(self):
        # Your solving algorithm goes here!
        pass

    # Makes it possible to print a board in a sensible format
    def __str__(self):
        r = "Board with " + str(self.n_rows) + " rows and " + str(self.n_cols) + " columns:\n"
        r += "[["
        for num in self.nums:
            for elem in num:
                r += elem.__str__() + ", "
            r = r[:-2] + "]" + "\n ["
        r = r[:-3] + "]"
        return r
    

class SudokuBoard(Board):
    def __init__(self, sudoku_board):
        self.nums = sudoku_board
        self.squares = []
        self.elems = []

    def _set_up_nums(self):
        for i in self.nums:
            for j in self.nums:
                self.squares.append(Squares(self.nums[i][j], None, None))

    def _set_up_elems(self):
        for i in self.squares: # rows
            for j in self.squares:
                self.squares[i][j].row = i

        for i in range(len(self.squares)):
            for j in range(len(self.squares)):
                self.squares[i][j].cols = [self.squares[row][i] for row in range(len(self.squares))]


        for i in range(0, 9, 3):    # (0, 3, 9) 
            for j in range(0, 9, 3):
                self.elems.append([self.nums[row][col] for row in range(i, i + 3) for col in range(j, j + 3)])
                


class Squares:
    def __init__(self, number, column, row, box):
        self.number = number
        self.col = column
        self.row = row
        self.box = box

    def is_legal(self, number):
        if not self.col.has_number() and not self.row.has_number() and not self.box.has_number():
            return True
        else:
            return False

    def set_number(self, number):
        if self.is_legal(number):
            self.number = number


class Element:
    def __init__(self):
        self.squares = []

    def has_number(self, number):
        for i in self.squares:
            if i.number == number:
                return True
            else:
                return False


if __name__ == "__main__":
    # Test code...
    reader = Sudoku_reader("sudoku_10.csv")
    board = Board(reader.next_board())
    print(board)