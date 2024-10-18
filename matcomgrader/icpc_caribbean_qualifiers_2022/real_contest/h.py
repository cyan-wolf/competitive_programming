
def det_new_orientation(orientation, direction):
    wheel = ['N', 'W', 'S', 'E']
    wheel_pos = None

    for i in range(len(wheel)):
        if wheel[i] == orientation:
            wheel_pos = i

    new_orientation = None

    match direction:
        case 'L':
            new_orientation = wheel[(wheel_pos + 1) % len(wheel)]
        case 'R':
            new_orientation = wheel[(wheel_pos - 1) % len(wheel)]

    return new_orientation

def det_commands_to_get_back(pos, orientation):
    if pos == [0, 0]:
        return 0
    
    elif pos[1] == 0:
        match orientation:
            case 'N', 'S':
                return 2
            
            case 'W':
                return 3 if pos[0] < 0 else 1
            
            case 'E':
                return 3 if pos[0] > 0 else 1
            
    elif pos[0] == 0:
        match orientation:
            case 'W', 'E':
                return 2
            
            case 'N':
                return 3 if pos[1] > 0 else 1
            
            case 'S':
                return 3 if pos[1] < 0 else 1
            
    else:
        match orientation:
            case 'N':
                return 3 if pos[1] < 0 else 4

            case 'S':
                return 3 if pos[1] > 0 else 4

            case 'W':
                return 3 if pos[0] > 0 else 4

            case 'E':
                return 3 if pos[0] < 0 else 4 

def det_shortest_path_back(commands):
    orientation = 'N'
    pos = [0, 0]

    for c in commands:
        if len(c) == 2:
            ds = int(c[1])

            match orientation:
                case 'N':
                    pos[1] += ds

                case 'S':
                    pos[1] -= ds

                case 'W':
                    pos[0] -= ds

                case 'E':
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
