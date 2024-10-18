
# ACCEPTED

def determine_encoding(matrix):
    count = {'0': 0, '1': 0}

    for row in matrix:
        for entry in row:
            count[entry] += 1

    if count['0'] > count['1']:
        return {'0': '*', '1': 'o'}
    
    elif count['0'] < count['1']:
        return {'0': 'o', '1': '*'}
    
    else:
        corner_entry = matrix[0][0]

        if corner_entry == '0':
            return {'0': '*', '1': 'o'}
        else:
            return {'0': 'o', '1': '*'}

def encode(matrix):
    encoding = determine_encoding(matrix)

    for r in range(len(matrix)):
        for c in range(len(matrix[r])):
            matrix[r][c] = encoding[matrix[r][c]]

def main():
    n = int(input())
    matrix = [list(input()) for _ in range(n)]

    encode(matrix)
    
    for row in matrix:
        print("".join(row))

if __name__ == "__main__":
    main()
