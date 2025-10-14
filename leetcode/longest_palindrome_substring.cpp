/**
 * Longest Palindromic Substring
 * https://leetcode.com/problems/longest-palindromic-substring/description/
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// TODO: Handle even-length palindromes.

string solution(string s) {
    int lptr_max = 0, len_max = 0;

    for (int i = 0; i < s.size(); ++i) {
        int lptr = i, rptr = i;

        while (true) {
            int new_lptr = lptr - 1;
            int new_rptr = rptr + 1;

            if (new_lptr < 0 || new_rptr >= s.size() || s[new_lptr] != s[new_rptr]) {
                break;
            }
            lptr = new_lptr;
            rptr = new_rptr;
        }

        int len = rptr - lptr + 1;
        if (len > len_max) {
            len_max = len;
        }
    }

    return s.substr(lptr_max, len_max);
}

class Solution {
public:
    string longestPalindrome(string s) {
        return solution(s);
    }
};

int main() {
    cout << solution("cbbd") << endl;
}