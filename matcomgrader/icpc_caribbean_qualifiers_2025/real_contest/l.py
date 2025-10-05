"""
https://matcomgrader.com/problem/9814/lost-score/
"""

# Accepted

def main():
    test_cases = int(input())

    for _ in range(test_cases):
        s1, s2 = [int(s) for s in input().split()]

        nums = [4, 2, 1]
        weights = [2, 2, 2]

        for score in [s1, s2]:
            for i in range(len(weights)):
                if score >= nums[i]:
                    score -= nums[i]
                    weights[i] -= 1

        last_score = 0

        for i in range(len(weights)):
            last_score += weights[i] * nums[i]

        print(last_score)

main()