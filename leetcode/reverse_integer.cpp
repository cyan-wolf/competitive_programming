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
    bool is_neg = false;

    if (x == INT_MIN) {
        return 0;
    }
    
    if (x < 0) {
        x *= -1;
        is_neg = true;
    }
    string s = to_string(x);

    reverse(s.begin(), s.end());

    if (is_neg) {
        s.insert(0, "-");
    }

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