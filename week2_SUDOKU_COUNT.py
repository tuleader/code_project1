def check(matran,row,col,num):
    for i in range(9):
        if matran[row][i] == num or matran[i][col] == num:
            return False
    start_row = 3*(row//3)
    start_col=3*(col//3)
    for i in range(start_row,start_row+3):
        for j in range(start_col,start_col+3):
            if matran[i][j] == num:
                return False
    return True
def count_sudoku(matran):
    for row in range(9):
        for col in range(9):
            if matran[row][col] == 0:
                count = 0
                for num in range(1,10):
                    if check(matran,row,col,num):
                        matran[row][col]=num
                        count +=count_sudoku(matran)
                        matran[row][col] = 0
                return count
    return 1
matran = [[int(j) for j in input().split()] for i in range(9)]
print(count_sudoku(matran))
