"""
https://matcomgrader.com/problem/9830/matrix-operations/
"""

# Accepted: FIRST EVER SOLVE in the ICPC Caribbean 2025 Qualifiers

def main():
    rows, cols, q = [int(s) for s in input().split()]

    matrix = [[int(s) for s in input().split()] for _ in range(rows)]

    for _ in range(q):
        fields = [int(s) for s in input().split()]
        test_type = fields[0]

        if test_type == 1:
            r = fields[1] - 1
            matrix[r] = matrix[r][::-1]

        elif test_type == 2:
            c = fields[1] - 1

            for r in range(rows // 2):
                matrix[r][c], matrix[rows - r - 1][c] = matrix[rows - r - 1][c], matrix[r][c]

        else:
            r, c = fields[1:]
            print(matrix[r - 1][c - 1])


main()