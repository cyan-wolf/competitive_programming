
# ACCEPTED

def repr_in_base(num, base):
    if num == 0:
        return "0"

    digits = []

    while num > 0:
        digits.append(str(num % base))
        num //= base

    return "".join(digits[::-1])

def main():
    case_amt = int(input())

    for _ in range(case_amt):
        num, base = [int(d) for d in input().split(" ")]

        print(repr_in_base(num, base))

if __name__ == "__main__":
    main()
