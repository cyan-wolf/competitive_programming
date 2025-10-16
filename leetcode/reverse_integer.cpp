/**
 * Reverse Integer
 * https://leetcode.com/problems/reverse-integer/description/
 * 
 * Given a signed 32-bit integer x, return x with its digits reversed. 
 * If reversing x causes the value to go outside the signed 32-bit integer 
 * range [-2^{31}, 2^{31} - 1], then return 0. Assume the environment does not allow 
 * you to store 64-bit integers (signed or unsigned).
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

using namespace std;

// Accepted

int solution(int x) {
    // Handle edge case (`INT_MIN` is negative, but it has no inverse).
    // It so happens that, according to the problem statement, `INT_MIN` should 
    // return 0, so that's what we do.
    if (x == INT_MIN) {
        return 0;
    }

    // Make the integer positive if it was negative.
    bool is_neg = x < 0;
    if (is_neg) {
        x *= -1;
    }
    // Reverse the digits of the integer as a string.
    string s = to_string(x);
    reverse(s.begin(), s.end());

    // Re-add the negative sign if the integer was negative.
    if (is_neg) {
        s.insert(0, "-");
    }

    // Try to parse the reversed integer digits as a 32-bit integer, 
    // if that ends up out of range, return 0 (as stated in the problem statement).
    try {
        int d = stoi(s);
        return d;
    }
    catch (out_of_range& ex) {
        return 0;
    }
}

// Unnecessary class for LeetCode submission.
class Solution {
public:
    int reverse(int x) {
        return solution(x);
    }
};

int main() {
    cout << solution(123) << endl;
    cout << solution(-123) << endl;
    cout << solution(120) << endl;
    cout << solution(INT_MIN) << endl;
}