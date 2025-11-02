/**
 * 3Sum Closest
 * https://leetcode.com/problems/3sum-closest/
 * 
 * Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
 * 
 * Return the sum of the three integers.
 * 
 * You may assume that each input would have exactly one solution.
 */

// Accepted

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int>& nums, int target) {
    // Keep track of the minimum distance to the target, 
    // and the assciated sum.
    int min_dist = INT_MAX;
    int min_sum = -1;

    // Check every triplet.
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            for (int k = j + 1; k < nums.size(); ++k) {
                int sum = nums[i] + nums[j] + nums[k];
                int dist = abs(sum - target);

                if (dist < min_dist) {
                    min_dist = dist;
                    min_sum = sum;
                }
            }
        }
    }
    return min_sum;
}

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        return solution(nums, target);
    }
};

int main() {
    vector<int> nums = {-1,2,1,-4};
    cout << solution(nums, 1) << endl;

    nums = {0,0,0};
    cout << solution(nums, 1) << endl;
}