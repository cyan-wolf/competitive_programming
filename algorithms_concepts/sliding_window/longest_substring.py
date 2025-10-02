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
    left = 0

    left_len = (left, 0)
    last_seen_map = {}

    for right in range(len(s)):
        curr = s[right]

        # Contract.
        # This contracts when the current character is within the window (at a position after or at `left`).
        if curr in last_seen_map and last_seen_map[curr] >= left:
            # Move `left` past where the other occurence of `curr` was in the window.
            left = last_seen_map[curr] + 1

        # Update state.
        last_seen_map[curr] = right

        # Update result.
        curr_len = right - left + 1
        old_len = left_len[1]

        if curr_len > old_len:
            left_len = (left, curr_len)
    
    start, length = left_len
    return s[start:start+length]


def main():
    print(find_longest_substr("aabc")) # abc
    print(find_longest_substr("bbbbb")) # b
    print(find_longest_substr("abcabcbb")) # abc


main()