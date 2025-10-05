"""
C - Sliding Grid
https://matcomgrader.com/problem/9838/sliding-grid/
"""

# Rejected: WRONG ANSWER

def main():
    test_cases = int(input())

    for _ in range(test_cases):
        length, height = [int(s) for s in input().split()]

        matrix = [[0 for _ in range(length)]for _ in range(height)]
        dir = 'R'
        rt = 0
        dt=0
        lt=0
        ut=0
        runing = True
        while runing:
            if dir == 'R':
                for i in range(length-rt):
                    print(i,'|',length )
                    if i+1<length and matrix[i][rt] > 0:
                        print("R")
                        runing = False
                    else:
                        matrix[i][rt] = 1
                rt+=1 
                dir = 'D'
            elif dir == 'D':
                for i in range(length-rt):
                    if i-1<length and matrix[dt][i+1] > 0:
                        print("D")
                        runing = False
                    else:
                        matrix[dt][i] = 1
                dt+=1 
                dir = 'L'
            elif dir == 'L':
                for i in range(length-lt):
                    if i+1<length and matrix[length-i-1][height-lt-1] > 0:
                        print("L")
                        runing = False
                    else:
                        matrix[length-i-1][lt] = 1
                lt+=1 
                dir = 'U'
            else:
                for i in range(length-ut):
                    if i<length and matrix[length-ut-1][height-i-1] > 0:
                        print("U")
                        runing = False
                    else:
                        matrix[length-ut-1][height-i-1] = 1
                ut+=1 
                dir= 'R'
main()
