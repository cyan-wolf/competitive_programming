
def solutionC():
    n = int(input())
    a = (int(c) for c in input().split(" "))
    elem_to_pos = {}
    pos_to_element = {}
    swaps = []

    for i in range(n):
        num = next(a)
        elem_to_pos[num] = i
        pos_to_element[i] = num

    for i in range(n):
        num = i + 1

        if elem_to_pos[num] != i:
            curr_num_pos = elem_to_pos[num]
            num_at_wrong_pos = pos_to_element[i]

            elem_to_pos[num] = i
            pos_to_element[i] = num

            elem_to_pos[num_at_wrong_pos] = curr_num_pos
            pos_to_element[curr_num_pos] = num_at_wrong_pos

            swaps.append((
                min(i + 1, curr_num_pos + 1),
                max(i + 1, curr_num_pos + 1),
            ))

    print(len(swaps))

    for swap in swaps:
        print(*swap)
            

def main():
    solutionC()


if __name__ == '__main__':
    main()