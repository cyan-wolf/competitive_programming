
# ACCEPTED

def max_abs_diff(nums):
    total_max = 0

    for i in range(len(nums)):
        max_ = 0

        for j in range(len(nums)):
            abs_dist = abs(nums[i] - nums[j])

            if abs_dist > max_:
                max_ = abs_dist

        if max_ > total_max:
            total_max = max_

    return total_max

def main():
    _ = input()
    nums = [int(c) for c in input().split(" ")]
    print(max_abs_diff(nums))

if __name__ == '__main__':
    main()
