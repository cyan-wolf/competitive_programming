/**
 * Integer to Roman
 * https://leetcode.com/problems/integer-to-roman/description/
 * 
 * Seven different symbols represent Roman numerals with the following values:
 * 
 * Symbol	Value
 * I	    1
 * V	    5
 * X	    10
 * L	    50
 * C	    100
 * D	    500
 * M	    1000
 * Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. 
 * Converting a decimal place value into a Roman numeral has the following rules:
 * 
 * If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted 
 * from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
 *
 * If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following 
 * symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following 
 * subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
 *
 * Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. 
 * You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use 
 * the subtractive form.
 *
 * Given an integer, convert it to a Roman numeral.
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

// Accepted

string solution(int num) {
    string acc;
    unordered_map<int, string> table;
    table[1000] = "M";
    table[500] = "D";
    table[100] = "C";
    table[50] = "L";
    table[10] = "X";
    table[5] = "V";
    table[1] = "I";

    while (num > 0) {
        for (int place = 3; place >= 0; --place) {
            int power = pow(10, place);
            if (num >= power) {
                int curr_digit = num / power;

                if (curr_digit == 4) {
                    acc.append(table.at(power));
                    acc.append(table.at(5 * power));
                }
                else if (curr_digit == 9) {
                    acc.append(table.at(power));
                    acc.append(table.at(power * 10));
                }
                else if (curr_digit < 4) {
                    for (int _i = 0; _i < curr_digit; ++_i) {
                        acc.append(table.at(power));
                    }
                }
                else if (curr_digit > 4) {
                    acc.append(table.at(5 * power));
                    curr_digit -= 5;

                    for (int _i = 0; _i < curr_digit; ++_i) {
                        acc.append(table.at(power));
                    }
                }

                num %= power;
            }
        }
    }

    return acc;
}

class Solution {
public:
    string intToRoman(int num) {
        return solution(num);
    }
};

int main() {
    cout << solution(1000) << endl;     // M
    cout << solution(3749) << endl;     // MMMDCCXLIX
    cout << solution(58) << endl;       // LVIII
    cout << solution(1994) << endl;     // MCMXCIV
}