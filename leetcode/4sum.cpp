/**
 * 4Sum
 * https://leetcode.com/problems/4sum/
 * 
 * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 *      0 <= a, b, c, d < n
 *      a, b, c, and d are distinct.
 *      nums[a] + nums[b] + nums[c] + nums[d] == target
 *      You may return the answer in any order.
 * 
 */

// Accepted

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct VectorKey {
    vector<int> data;

    bool operator==(const VectorKey& other) const {
        return data == other.data;
    }
};

struct VectorHash {
    size_t operator()(const VectorKey& k) const {
        size_t seed = k.data.size();
        hash<int> hasher;

        for (const int& n : k.data) {
            seed ^= hasher(n) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

vector<vector<int>> solution(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); ++i) {
        seen[nums[i]] = i;
    }
    unordered_set<VectorKey, VectorHash> solutions;

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            for (int k = j + 1; k < nums.size(); ++k) {
                // The `long long` casting is to avoid overflow.
                long long needed = (long long)target - (long long)nums[i] - (long long)nums[j] - (long long)nums[k];

                if (needed > INT_MAX || needed < INT_MIN) {
                    continue;
                }

                auto it = seen.find(needed);
                if (it != seen.end() && it->second > k) {
                    vector<int> quadruplet = {nums[i], nums[j], nums[k], it->first};
                    sort(quadruplet.begin(), quadruplet.end());

                    solutions.insert({quadruplet});
                }
            }
        }
    }

    vector<vector<int>> solutions_vec;
    for (auto q : solutions) {
        solutions_vec.push_back(q.data);
    }
    return solutions_vec;
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return solution(nums, target);
    }
};

int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    auto solutions = solution(nums, 0);

    for (auto quadruplets : solutions) {
        for (int n : quadruplets) {
            cout << n << " ";
        }
        cout << endl;
    }
    cout << endl;

    nums = {2,2,2,2,2};
    solutions = solution(nums, 8);

    for (auto quadruplets : solutions) {
        for (int n : quadruplets) {
            cout << n << " ";
        }
        cout << endl;
    }
    cout << endl;
}