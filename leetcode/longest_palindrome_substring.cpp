/**
 * Longest Palindromic Substring
 * https://leetcode.com/problems/longest-palindromic-substring/description/
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Accepted

string solution(string s) {
    int lptr_max = 0, len_max = 0;

    // This encodes 2 for loops in one.
    // For any given iteration, the index being considered is 
    // `int idx = i_encoded / 2`.
    // Here, `idx` is always a valid index into the string.
    // By convention in this code, when the encoded index is even, 
    // it means we are in "mode 1" and when it is odd we are in "mode 2".
    //
    // In mode 1, we are looking for even length palindromes. So we nudge 
    // the right pointer by 1. Before the while loop, common-sense checks are 
    // made that this nudged pointer is a valid index into the string and that 
    // the starting window is a valid palindrome (which is the case if 
    // `s[lptr] == s[rptr]`). 
    //
    // In mode 2, we are looking for odd length palindromes. Here, both pointers 
    // start at the same index (which we already know is valid), and a 1 element 
    // window is always a palindrome, so no pre-while checks are needed.
    for (int i_encoded = 0; i_encoded < s.size() * 2; ++i_encoded) {
        int idx = i_encoded / 2;
        int lptr = idx, rptr = idx;

        if (i_encoded % 2 == 0) {
            rptr += 1;
        }
        if (rptr >= s.size()) {
            continue;
        }
        if (s[lptr] != s[rptr]) {
            continue;
        }

        while (true) {
            int new_lptr = lptr - 1;
            int new_rptr = rptr + 1;

            // Try growing from both sides.
            if (new_lptr >= 0 && new_rptr < s.size() && s[new_lptr] == s[new_rptr]) {
                lptr = new_lptr;
                rptr = new_rptr;
            }
            // No way to grow while still maintaining the palindrome.
            else {
                break;
            }
        }

        // If the length is bigger than the previous longest length, 
        // then save the left pointer and the length to construct the 
        // substring at the end.
        int len = rptr - lptr + 1;
        if (len > len_max) {
            lptr_max = lptr;
            len_max = len;
        }
    }

    return s.substr(lptr_max, len_max);
}

// Unnecessary class for LeetCode submission.
class Solution {
public:
    string longestPalindrome(string s) {
        return solution(s);
    }
};

int main() {
    cout << solution("babad") << endl;
    cout << solution("cbbd") << endl;

    cout << solution("aacabdkacaa") << endl; // aca
    cout << solution("aaaa") << endl; // aaaa
    cout << solution("ccc") << endl; // ccc
}