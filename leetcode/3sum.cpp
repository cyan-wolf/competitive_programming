/**
 * 3Sum
 * https://leetcode.com/problems/3sum/description/
 * 
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * Notice that the solution set must not contain duplicate triplets.
 */

// Accepted

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> solution(const vector<int>& nums) {
    unordered_map<int, int> num_positions;
    set<vector<int>> triplets;

    for (int i = 0; i < nums.size(); ++i) {
        num_positions[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (i == j) {
                continue;
            }
            auto it = num_positions.find(-(nums[i] + nums[j]));

            if (it != num_positions.end() && it->second > j) {
                vector<int> triplet = {nums[i], nums[j], it->first};
                sort(triplet.begin(), triplet.end());
                triplets.insert(triplet);
            }
        }
    }
    vector<vector<int>> triplets_vec;
    for (auto t : triplets) {
        triplets_vec.push_back(t);
    }
    return triplets_vec;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        return solution(nums);
    }
};

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    auto res = solution(nums);

    for (const auto& triplet : res) {
        cout << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << endl;
    }
}