
# ACCEPTED

def det_new_orientation(orientation, direction):
    wheel = ['N', 'W', 'S', 'E']
    wheel_pos = None

    for i in range(len(wheel)):
        if wheel[i] == orientation:
            wheel_pos = i

    new_orientation = None

    if direction == 'L':
        new_orientation = wheel[(wheel_pos + 1) % len(wheel)]
    else:
        new_orientation = wheel[(wheel_pos - 1) % len(wheel)]

    return new_orientation

def det_commands_to_get_back(pos, orientation):
    if pos == [0, 0]:
        return 0
    
    elif pos[1] == 0:
        if orientation in {'N', 'S'}:
            return 2
            
        elif orientation == 'W':
            return 3 if pos[0] < 0 else 1
            
        else:
            return 3 if pos[0] > 0 else 1
            
    elif pos[0] == 0:
        if orientation in {'W', 'E'}:
            return 2
            
        elif orientation == 'N':
            return 3 if pos[1] > 0 else 1
            
        else:
            return 3 if pos[1] < 0 else 1
            
    else:
        if orientation == 'N':
            return 3 if pos[1] < 0 else 4

        elif orientation == 'S':
            return 3 if pos[1] > 0 else 4

        elif orientation == 'W':
            return 3 if pos[0] > 0 else 4

        else:
            return 3 if pos[0] < 0 else 4 

def det_shortest_path_back(commands):
    orientation = 'N'
    pos = [0, 0]

    for c in commands:
        if len(c) == 2:
            ds = int(c[1])

            if orientation == 'N':
                pos[1] += ds

            elif orientation == 'S':
                pos[1] -= ds

            elif orientation == 'W':
                pos[0] -= ds

            else:
                pos[0] += ds
        else:
            direction = c[0]
            orientation = det_new_orientation(orientation, direction)

    return det_commands_to_get_back(pos, orientation)

def main():
    n = int(input())
    commands = [input().split() for _ in range(n)]

    print(det_shortest_path_back(commands))

if __name__ == "__main__":
    main()
