
# ACCEPTED

import math

def get_sum_divs(num):
    sum_divs = 0
    divs = set()

    for i in range(2, int(math.sqrt(num) + 1)):
        if num % i == 0:
            compl = num // i

            if i not in divs:
                sum_divs += i
                divs.add(i)

            if compl not in divs:
                sum_divs += compl
                divs.add(compl)

    return sum_divs

def det_first_last_good_numbers(low, high):
    first_last = [-1, -1]

    # From below.
    for num in range(low, high + 1):
        if get_sum_divs(num) > num:
            first_last[0] = num
            break

    # If no good numbers were found, give up early.
    if first_last[0] != -1:
        # From above.
        for num in range(high, low - 1, -1):
            if get_sum_divs(num) > num:
                first_last[1] = num
                break

    return [str(d) for d in first_last]

def main():
    low, high = [int(d) for d in input().split()]

    print(" ".join(det_first_last_good_numbers(low, high)))

if __name__ == "__main__":
    main()