/**
 * First Missing Positive
 * https://leetcode.com/problems/first-missing-positive/description/
 * 
 * Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums. 
 * 
 * You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
 */

// Accepted

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int>& nums) {
    // We are looking for the smallest positive number not in present in the array. 
    // We notice that the value that we are looking for is at most `n + 1`. For example, 
    // if nums = [1, 4, 2, 3] then the answer is 5. We know this since the array contains 
    // all the numbers in the range 1 to n (inclusive). We can encode the presence of the numbers in 
    // this range by using an encoding. If the entry at index i is negative, then the number i + 1 was found 
    // in the array. For example, if n = [1, 4, 2, 3], the encoding would be:
    //         [-1, -4, -2, -3]
    // found?    1   2   3   4
    // 
    // Since the numbers 1 to 4 are in the array, the answer is n + 4 = 5.
    // 
    // Using this encoding, we can easily find the smallest positive number not in the array for the case 
    // when a number in the range 1 to n is missing. For example:
    //
    // nums = [1, 1, 4, 2]
    //             |
    //             V
    //        [-1, -1, 4, -2]
    // found?   1   2  3   4
    //
    // As seen above, in the encoded version of the array, we see that the entry corresponding 
    // to 3 is positive, meaning it was not found. By doing a pass over the encoded array, we can 
    // find this out and determine that 3 was not in the array and therefore is the answer.
    
    // First pass: Set all negative numbers to 0, since we use negative numbers 
    // for marking later.
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < 0) {
            nums[i] = 0;
        }
    }

    // Second pass: Iterate over every number nums_i. If nums_i is within the range 1 to n (inclusive), 
    // then mark the entry at the (i - 1)th position in the array as visited (by marking it as negative). 
    // Since this can happen in any order, a cell we are visiting might have already been marked. To mitigate this, 
    // we only consider the absolute value of the number at the cell. 
    // 
    // We special case 0. When a cell containing 0 is marked, since 0 = -0, we instead use -(n + 1). We are only 
    // looking for numbers up to n, so finding -(n + 1) results in us processing `n + 1`, which is outside of the 
    // range we care about.
    for (int i = 0; i < nums.size(); ++i) {
        int num_abs = abs(nums[i]);

        if (num_abs > 0 && num_abs <= nums.size()) {
            if (nums[num_abs - 1] > 0) {
                nums[num_abs - 1] *= -1;
            }
            else if (nums[num_abs - 1] == 0) {
                nums[num_abs - 1] = -(nums.size() + 1);
            }
        }
    }

    // If no missing number is found below, it means that all numbers from 1 to n 
    // were in the array, meaning that the next number is n + 1.
    int missing = nums.size() + 1;

    // Third pass: Checking if any entry is non-negative. The first non-negative entry 
    // corresponds to the missing number.
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] >= 0) {
            missing = i + 1;
            break;
        }
    }

    return missing;
}

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        return solution(nums);
    }
};

int main() {
    vector<int> nums = {2, 1, 0};
    cout << solution(nums) << endl;

    nums = {3,4,-1,1};
    cout << solution(nums) << endl;

    nums = {7,8,9,11,12};
    cout << solution(nums) << endl;
}