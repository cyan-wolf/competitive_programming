




def solutionA():
    a, b = [int(c) for c in input().split(" ")]

    for i in range(10):
        if i != a + b:
            print(i)
            return
        

def solutionB():
    row_amt = int(input())

    for _ in range(row_amt):
        row = (int(c) for c in input().split(" "))
        vertices = []

        for i in range(row_amt):
            is_present = next(row) == 1

            if is_present:
                vertices.append(str(i + 1))

        print(" ".join(vertices))


def solutionC():
    import math

    n = int(input())

    max_palindromic_cube = None

    cubes = (i * i * i for i in range(1, n))
    
    for cube in cubes:
        if cube > n:
            break

        cube_str = str(cube)

        if cube_str == cube_str[::-1]:
            max_palindromic_cube = cube
    
    print(max_palindromic_cube)



def main():
    solutionC()


if __name__ == '__main__':
    main()
