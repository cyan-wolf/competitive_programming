
def det_min_cost(nums):
    nums.sort()
    cost = 0

    for i in range(len(nums) - 1):
        cost += nums[i+1] - nums[i]

    return cost

def main():
    _ = input()
    nums = [int(c) for c in input().split()]
    print(det_min_cost(nums))

if __name__  == "__main__":
    main()
