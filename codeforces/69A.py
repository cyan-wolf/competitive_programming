
# ACCEPTED

def main():
    n = int(input())

    sums = [0 for _ in range(3)]

    for _ in range(n):
        x, y, z = [int(d) for d in input().split()]

        sums[0] += x
        sums[1] += y
        sums[2] += z

    if all(s == 0 for s in sums):
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()
