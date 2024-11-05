# TODO: problems figuring out path logic

from enum import Enum

class Dir(Enum):
    DOWN = 0
    RIGHT = 1
    LEFT = 2
    UP = 3

def in_bounds(matrix, pos):
    x, y = pos
    return 0 <= x < len(matrix) and 0 <= y < len(matrix)

def visited(matrix, pos):
    if in_bounds(matrix, pos):
        x, y = pos
        return matrix[y][x]
    
    return False

def movable_into(matrix, pos):
    if in_bounds(matrix, pos):
        x, y = pos
        return not matrix[y][x]
    
    return False

def gen_matrix_path_positions(dimensions):
    dir_cycle = [Dir.DOWN, Dir.RIGHT, Dir.UP, Dir.LEFT]

    matrix = [[False for _ in range(dimensions)] for _ in range(dimensions)]
    dir_ = -1
    pos = (0, 0)
    path_positions = []
    path_progress = 1

    inv_test = {}

    while True:
        dir_ = (dir_ + 1) % len(dir_cycle)
        direction = dir_cycle[dir_]

        x, y = pos

        if direction == Dir.DOWN:
            new_pos = (x, y + 1)

        elif direction == Dir.RIGHT:
            new_pos = (x + 1, y)

        elif direction == Dir.UP:
            new_pos = (x, y - 1)

        elif direction == Dir.LEFT:
            new_pos = (x - 1, y)

        if movable_into(matrix, new_pos):
            path_positions.append((x + 1, y + 1))
            inv_test[pos] = path_progress
            matrix[y][x] = True
            pos = new_pos
            path_progress += 1

        if path_progress == dimensions**2:
            path_positions.append((x + 1, y + 1))
            inv_test[pos] = path_progress
            break

    for r in range(dimensions):
        row = []
        for c in range(dimensions):
            progress = f"{(inv_test[(c, r)]):3d}" if (c, r) in inv_test else '  X'
            row.append(progress)

        print("".join(row))

    return path_positions

def main():
    test_cases, dimensions = [int(d) for d in input().split()]

    path_positions = gen_matrix_path_positions(dimensions)

    for _ in range(test_cases):
        path_pos = int(input())
        print(path_positions[path_pos - 1])

if __name__ == "__main__":
    main()
