/**
 * Letter Combinations of a Phone Number
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 * 
 * Given a string containing digits from 2-9 inclusive, return all possible letter 
 * combinations that the number could represent. Return the answer in any order. 
 * A mapping of digits to letters (just like on the telephone buttons) is given below. 
 * Note that 1 does not map to any letters.
 */

// Accepted

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <tuple>

using namespace std;

vector<string> solution(string digits) {
    if (digits.size() == 0) {
        return {};
    }

    unordered_map<char, string> letters;
    letters['2'] = "abc";
    letters['3'] = "def";
    letters['4'] = "ghi";
    letters['5'] = "jkl";
    letters['6'] = "mno";
    letters['7'] = "pqrs";
    letters['8'] = "tuv";
    letters['9'] = "wxyz";

    // Vector for storing all the solutions.
    vector<string> solutions;

    // Initialize the stack with a starting base pair of values.
    // The first element is the current index into `digits` and the second 
    // element is the current string accumulator.
    vector<tuple<int, string>> stk;
    stk.push_back({0, ""});

    while (stk.size() > 0) {
        auto [curr_idx, curr_acc] = stk.back();
        stk.pop_back();

        // If `curr_idx` is just past the last index, that means 
        // that we have already processed everything and we can 
        // add `curr_acc` as a solution.
        if (curr_idx == digits.size()) {
            solutions.push_back(curr_acc);
        }

        // Branch off for all possible choices of `c` for the digit 
        // at `curr_idx`.
        for (char c : letters[digits[curr_idx]]) {
            string new_acc = curr_acc;
            new_acc.push_back(c);

            stk.push_back({curr_idx + 1, new_acc});
        }
    }

    return solutions;
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        return solution(digits);
    }
};

int main() {
    auto solutions = solution("2");

    for (const auto& sol : solutions) {
        cout << "'" << sol << "' ";
    }
    cout << endl;
}