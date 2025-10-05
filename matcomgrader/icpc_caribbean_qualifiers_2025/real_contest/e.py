"""
https://matcomgrader.com/problem/9813/exact-steps/
"""

# Accepted

def main():
    def binarySearch(low, high, steps):
        if low > high:
            return

        mid = (low + high) // 2
        if steps == 1:
            foo.add(mid)
            return
        
        binarySearch(low,mid-1, steps-1)
        binarySearch(mid+1,high, steps-1)

    test_cases = int(input())
    if test_cases > 100:
        test_cases = 100

    for _ in range(test_cases):
        foo = set()
        length, steps = [int(s) for s in input().split()]
        if length >=1 and length <= 100_000:
            binarySearch(0 , length-1, steps)
            nums = sorted(list(foo))
            if len(foo) >= 1:
                print(' '.join(([str(elem) for elem in nums])))

main()
