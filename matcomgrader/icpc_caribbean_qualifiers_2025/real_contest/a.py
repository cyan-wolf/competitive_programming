"""
https://matcomgrader.com/problem/9835/altered-states/
"""

# Rejected: WRONG ANSWER

def main():
    foo = set()
    test_cases = int(input())
    if test_cases >= 1 and test_cases <= 5.5 * 100000:

        for _ in range(test_cases):
            
            str = input()
            if any([c.isupper() for c in str]):
                continue
            l=0
            while l <= len(str):
                for i in range(len(str)):
                    foo.add(str[i:i+l+1])
                l+=1
    if len(foo) <= 5.5 * 100000:
        print(len(foo))

        
main()