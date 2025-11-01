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

    // Collect all the number's digits in reverse order.
    int x_copy = x;

    // Use `long long` to avoid overflow.
    long long rev_x = 0;

    while (x_copy != 0) {
        rev_x = rev_x * 10 + (x_copy % 10);
        x_copy /= 10;
    }

    // Check if the integer is the same as its reverse..
    return x == rev_x;
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