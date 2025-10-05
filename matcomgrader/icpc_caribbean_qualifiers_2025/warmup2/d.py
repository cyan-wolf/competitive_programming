"""
https://matcomgrader.com/problem/9839/fast-flight/
"""

# Rejected: RUNTIME ERROR (likely due to parsing the input with `int` instead of `float`)

def main():
    test_cases = int(input())
    # x = float('inf')
    # if test_cases > 100:
    #     runs = 100
    # else:
    #     runs = test_cases

    test_cases = min(100, test_cases)

    for _ in range(test_cases):
        dist, v1, v2, v_fly = [int(s) for s in input().split()]
        if dist <= 0:
            print("0.00")
        elif (v1 + v2) == 0:
            print(float('inf'))
        else:
            t = dist / (v1 + v2)
            dist_fly = v_fly * t

            print(f"{dist_fly:.2f}")



main()

# def main2():
#     test_cases = int(input())

#     for _ in range(test_cases):
#         dist, v1, v2, v_fly = [int(s) for s in input().split()]

#         if distM - dist



# main2()
