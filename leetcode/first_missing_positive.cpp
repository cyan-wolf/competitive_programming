/**
 * First Missing Positive
 * https://leetcode.com/problems/first-missing-positive/description/
 * 
 * Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums. 
 * 
 * You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
 */

// Accepted
// (*) Uses O(n) space instead of O(1).

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int>& nums) {
    int missing = 1;
    unordered_set<int> seen;

    for (int n : nums) {
        if (n == missing) {
            missing++;
        }
        if (n > 0) {
            seen.insert(n);
        }
    }

    while (seen.count(missing) != 0) {
        missing++;
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