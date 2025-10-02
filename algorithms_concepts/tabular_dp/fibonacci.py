"""
Fibonacci.
"""

# O(n)
def calc_fibonacci(n: int) -> int:
    if n == 0 or n == 1:
        return n

    dp = [0 for _ in range(n + 1)]

    dp[0] = 0
    dp[1] = 1

    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[n]


# O(n)
def calc_fibonacci_mem(n: int) -> int:
    cache = {}

    def mem(n: int) -> int:
        if n == 0 or n == 1:
            cache[n] = n
            return n
        
        elif n in cache:
            return cache[n]
        
        else:
            fib = mem(n - 1) + mem(n - 2)
            cache[n] = fib
            return fib
    
    return mem(n)


def main():
    FIB_AMT = 10

    for i in range(FIB_AMT):
        print(f"{i}th -> {calc_fibonacci(i)}")


main()
