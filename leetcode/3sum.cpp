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
#include <set> // increases complexity due to O(log N) operations (instead of O(1))

using namespace std;

vector<vector<int>> solution(const vector<int>& nums) {
    unordered_map<int, int> num_positions;
    set<vector<int>> triplets;

    // Cache the positions in a hash map.
    // This allows easy retrieval of a number and its index.
    // Note that this removes duplicates, but this doesn't matter since at the end 
    // the triplets have to be unique anyways, so multiple positions for the same 
    // number are not considered for the retrieval stage.
    for (int i = 0; i < nums.size(); ++i) {
        num_positions[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (i == j) {
                continue;
            }
            // Find the number that makes the partial sum be 0.
            auto it = num_positions.find(-(nums[i] + nums[j]));

            if (it != num_positions.end() && it->second > j) {
                vector<int> triplet = {nums[i], nums[j], it->first};
                // Makes the representation of the triplet unique.
                sort(triplet.begin(), triplet.end());
                // Takes case of duplicates since `triplets` is a map.
                // NOTE: O(log N) since `map` is used instead of `unordered_map`.
                triplets.insert(triplet);
            }
        }
    }
    // Turn the map into a vector as the problem statement requires.
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