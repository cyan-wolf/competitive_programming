
def determine_max_stack_size(stk):
    max_size = 1

    for i in range(len(stk) - 1):
        acc = stk[i]
        size = 1

        pos1, pos2 = i, i + 1

        while pos2 < len(stk):
            if acc < stk[pos2]:
                size += 1
                acc += stk[pos2]
                pos1 += 1
            
            pos2 += 1

        if size > max_size:
            max_size = size

    return max_size
            
def main():
    n =  int(input())
    cakes = [int(input()) for _ in range(n)]
    cakes.sort()
    print(determine_max_stack_size(cakes))

if __name__ == '__main__':
    main()
