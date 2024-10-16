
# ACCEPTED

def max_consec_subset(nums):
    nums = list(set(nums)) # remove duplicates
    nums.sort()
    max_streak = 0
    
    for i in range(len(nums)):
        num = nums[i]
        streak = 1

        for j in range(i + 1, len(nums)):
            num += 1
            if nums[j] == num:
                streak += 1
            
            else:
                break
        
        if streak > max_streak:
            max_streak = streak
    
    return max_streak

def main():
    _ = input()
    nums = [int(c) for c in input().split(" ")]
    print(max_consec_subset(nums))

if __name__ == '__main__':
    main()
