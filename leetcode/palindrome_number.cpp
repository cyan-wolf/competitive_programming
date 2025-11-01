/**
 * Palindrome Number
 * https://leetcode.com/problems/palindrome-number/description/
 * 
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 */

// Accepted

#include <iostream>
#include <vector>

using namespace std;

bool solution(int x) {
    // According to the problem statement, negative numbers are automatically not
    // palindromic. So if a number is less than or equal to 0, we return true if x == 0 
    // else false (0 is a palindrome).
    if (x <= 0) {
        return x == 0;
    }

    // Collect all the number's digits.
    vector<int> digits;

    while (x != 0) {
        digits.push_back(x % 10);
        x /= 10;
    }

    // Check if the list of digits is a palindrome.
    for (int i = 0; i < digits.size() / 2; ++i) {
        if (digits[i] != digits[digits.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

class Solution {
public:
    bool isPalindrome(int x) {
        return solution(x);
    }
};

int main() {
    cout << solution(121) << endl; // 1

    cout << solution(10) << endl; // 0
}