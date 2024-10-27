
# ACCEPTED

def gen_sortable_permutation(n):
    nums = list(range(1, n + 1))

    for i in range(len(nums) - 1, 0, -1):
        nums[i], nums[i - 1] = nums[i - 1], nums[i]

    return " ".join([str(d) for d in nums])


def main():
    n = int(input())
    print(gen_sortable_permutation(n))


if __name__ == "__main__":
    main()