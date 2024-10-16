
# ACCEPTED

def det_palindrome_len(s):
    letter_count = {}

    for c in s:
        letter_count.setdefault(c, 0)
        letter_count[c] += 1

    odd_lets = []

    for c in letter_count:
        if letter_count[c] % 2 == 1:
            odd_lets.append((c, letter_count[c]))

    if len(odd_lets) in {0, 1}:
        return len(s)
    
    # Remove 1 from all except one of the odd frequency letters to make them even.
    else:
        return len(s) - (len(odd_lets) - 1)

def main():
    print(det_palindrome_len(input()))

if __name__ == "__main__":
    main()