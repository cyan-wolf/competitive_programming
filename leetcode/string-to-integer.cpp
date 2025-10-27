/**
 * String to Integer
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 * 
 * Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
 * 
 * The algorithm for myAtoi(string s) is as follows:
 * 
 * - Whitespace: Ignore any leading whitespace (" ").
 * - Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
 * - Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
 * - Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
 * - Return the integer as the final result.
 */

// Accepted

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int solution(string s) {
    string acc;
    bool reading_whitespace = true;
    bool checking_sign = false;
    bool is_negative = false;

    for (char c : s) {
        // Skip past trailing whitespace.
        if (reading_whitespace) {
            if (c == ' ') {
                continue;
            }
            // When a non-whitespace character is found, we stop 
            // skipping past whitespace and start looking for the sign.
            reading_whitespace = false;
            checking_sign = true;
        }

        if (checking_sign) {
            // We only look for the sign in this iteration, so we immediately 
            // flip this flag.
            checking_sign = false;

            // Ignore a leading plus sign.
            if (c == '+') {
                continue;
            }
            // Ignore a leading negative sign but trigger the `is_negative` flag.
            else if (c == '-') {
                is_negative = true;
                continue;
            }
        }

        // Add digits to the accumulator until a non-digit, if any, is found.
        if (is_digit(c)) {
            acc.push_back(c);
        }
        else {
            break;
        }
    }

    try {
        // If the digit was negative, insert it to the front to the string, this is 
        // O(n) but fine given the constraints.
        if (is_negative) {
            acc.insert(0, "-");
        }
        
        // Try parsing into a 32-bit integer.
        int i = stoi(acc);
        return i;
    }
    catch (out_of_range) {
        // If we got an `out_of_range` exception while parsing, use the negation flag to 
        // automatically return the minimum/maximum possible integer (expected behavior according
        // to the problem statement).
        return (is_negative) ? INT_MIN : INT_MAX;
    }
    catch (invalid_argument) {
        // The above logic builds invalid accumulators when the original string is unparsable 
        // (according to the problem statement) so we just return 0 (failure) if we fail to parse 
        // the accumulator.
        return 0;
    }
}

class Solution {
public:
    int myAtoi(string s) {
        return solution(s);
    }
};


int main() {
    cout << solution("42") << endl; // 42
    cout << solution(" -042") << endl; // -42
    cout << solution("1337c0d3") << endl; // 1337
    cout << solution("0-1") << endl; // 0
    cout << solution("words and 987") << endl; // 0
}