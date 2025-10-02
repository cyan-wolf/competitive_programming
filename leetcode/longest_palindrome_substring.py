
def is_palindrome_slow(s: str) -> bool:
    if len(s) % 2 == 0:
        left = s[:len(s) // 2]
        right = s[len(s) // 2:]
    else:
        left = s[:len(s) // 2 + 1]
        right = s[len(s) // 2:]

    # this ------> vvvvvvvvvvv is extremely slow
    return left == right[::-1]


def longest_palindrome_substr(s: str) -> str:
    known_palindromes = set()

    def is_palindrome(s: str) -> bool:
        if len(s) == 0:
            return True
        
        elif s in known_palindromes:
            return True
        
        middle = s[1:len(s) - 1]

        if s[0] != s[-1]:
            return False
        
        else:
            has_palindromic_middle = is_palindrome(middle)

            if has_palindromic_middle:
                known_palindromes.add(s)

            return has_palindromic_middle


    max_palindrome = ""

    for i in range(len(s)):
        for j in range(i, len(s)):
            curr = s[i:j + 1]
            
            if is_palindrome(curr) and len(curr) > len(max_palindrome):
                max_palindrome = curr

    return max_palindrome


def main():
    s = "babad"
    result = longest_palindrome_substr(s)
    print(result)


if __name__ == "__main__":
    main()
