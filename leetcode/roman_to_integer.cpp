/**
 * Roman to Integer
 * 
 * 
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * Symbol       Value
 *   I             1
 *   V             5
 *   X             10
 *   L             50
 *   C             100
 *   D             500
 *   M             1000
 * For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given a roman numeral, convert it to an integer.
 */

// Accepted

#include <iostream>
#include <string>

using namespace std;

char safe_get(const string& s, int i) {
    if (i >= s.size()) {
        return 'Z'; // sentinel
    }
    return s[i];
}

int solution(string s) {
    int i = 0;
    int acc = 0;
    
    while (i < s.size()) {
        char curr = s[i];
        // Returns a sentinel if `i + 1` is out of bounds. Does not 
        // interfere with the if statements below.
        char next = safe_get(s, i + 1);

        // If statements handling every possible combination of characters.
        if (curr == 'I') {
            if (next == 'V') {
                acc += 4;
                i += 2;
            }
            else if (next == 'X') {
                acc += 9;
                i += 2;
            }
            else {
                acc += 1;
                i++;
            }
        }
        else if (curr == 'X') {
            if (next == 'L') {
                acc += 40;
                i += 2;
            }
            else if (next == 'C') {
                acc += 90;
                i += 2;
            }
            else {
                acc += 10;
                i++;
            }
        }
        else if (curr == 'C') {
            if (next == 'D') {
                acc += 400;
                i += 2;
            }
            else if (next == 'M') {
                acc += 900;
                i += 2;
            }
            else {
                acc += 100;
                i++;
            }
        }
        else {
            if (curr == 'V') {
                acc += 5;
            } else if (curr == 'L') {
                acc += 50;
            } else if (curr == 'D') {
                acc += 500;
            } else {
                acc += 1000;
            }
            i++;
        }
    }
    return acc;
}

class Solution {
public:
    int romanToInt(string s) {
        return solution(s);
    }
};

int main() {
    cout << solution("III") << endl;        // 3
    cout << solution("LVIII") << endl;      // 58
    cout << solution("MCMXCIV") << endl;    // 1994
}