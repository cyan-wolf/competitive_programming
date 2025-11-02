/**
 * Longest Common Prefix
 * https://leetcode.com/problems/longest-common-prefix/
 * 
 * Write a function to find the longest common prefix string amongst an array of strings.
 * 
 * If there is no common prefix, return an empty string "".
 */

// Accepted

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(vector<string>& strs) {
    int idx = 0;
    string acc;

    while (true) {
        char curr = '\0'; // nul byte to signal that `curr` is uninitialized
        bool all_same_at_idx = true;

        // Check that all the strings have `curr` at `idx`.
        // If so, add `curr` to the prefix and increment the index.
        for (const string& s : strs) {
            // We found the end of a string, automatically stop searching.
            if (idx >= s.size()) {
                all_same_at_idx = false;
                break;
            }
            // Initialize `curr` (happens in the first iteration).
            if (curr == '\0') {
                curr = s[idx];
                continue;
            }

            if (s[idx] != curr) {
                all_same_at_idx = false;
                break;
            }
        }

        if (!all_same_at_idx) {
            break;
        }
        acc.push_back(curr);
        idx++;
    }

    return acc;
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        return solution(strs);
    }
};

int main() {
    vector<string> strs = {"flower","flow","flight"};
    cout << solution(strs) << endl;

    strs = {"dog","racecar","car"};
    cout << solution(strs) << endl;
}