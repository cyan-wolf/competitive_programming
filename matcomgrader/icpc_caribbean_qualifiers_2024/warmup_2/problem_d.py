
# ACCEPTED

def can_win(p1, p2):
    for p in p1:
        if p in p2:
            return "YES"
        
    return "NO"

def main():
    nums = [int(c) for c in input().split()]
    print(can_win(nums[0:2], nums[2:]))

if __name__ == "__main__":
    main()
