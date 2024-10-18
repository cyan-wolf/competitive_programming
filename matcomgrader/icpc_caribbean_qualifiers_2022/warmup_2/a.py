
# ACCEPTED

import itertools

def print_permutations(n):
    for perm in itertools.permutations(range(1, n+1)):
        perm_str = " ".join([str(d) for d in perm])
        print(perm_str)

def main():
    n = int(input())
    print_permutations(n)

if __name__ == "__main__":
    main()
