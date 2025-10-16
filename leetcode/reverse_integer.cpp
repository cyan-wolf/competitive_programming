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

using namespace std;

int solution(int x) {
    // TODO: ...
    return -1;
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
    cout << solution(121) << endl;
}