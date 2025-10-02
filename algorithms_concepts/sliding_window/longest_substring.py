"""
Given a string S, find the length of the longest contiguous substring that contains no repeating characters.
"""

# O(n) (?)
# actually O(n^6)
# wrong implementation vvv
def find_longest_substr_incorrect(s: str) -> str:
    left = 0
    right = 0

    seen = set()
    longest = ""

    last_idx = len(s) - 1

    while right < last_idx:
        curr = s[right]

        if curr in seen:
            seen.remove(s[left])
            left += 1

        else:
            seen.add(curr)

            sub = s[left:right+1]
            if len(sub) > len(longest):
                longest = sub

            right += 1
     
    return longest


def find_longest_substr(s: str) -> str:
    # TODO
    return ""


def main():
    print(find_longest_substr_incorrect("aabc")) # abc
    print(find_longest_substr_incorrect("bbbbb")) # b
    print(find_longest_substr_incorrect("abcabcbb")) # abc


main()