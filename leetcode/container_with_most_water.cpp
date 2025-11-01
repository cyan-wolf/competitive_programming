/**
 * Container with Most Water
 * https://leetcode.com/problems/container-with-most-water/description/
 * 
 * You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
 * 
 * Find two lines that together with the x-axis form a container, such that the container contains the most water.
 * 
 * Return the maximum amount of water a container can store.
 * 
 * Notice that you may not slant the container.
 */

// Time Limit Exceeded

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int>& height) {
    int max_area = 0;

    for (int i = 0; i < height.size(); ++i) {
        for (int j = i; j < height.size(); ++j) {
            int dx = j - i;
            int dy = min(height[i], height[j]);

            int area = dx * dy;
            if (area > max_area) {
                max_area = area;
            }
        }
    }
    return max_area;
}

class Solution {
public:
    int maxArea(vector<int>& height) {
        return solution(height);
    }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << solution(height) << endl;

    height = {1,1};
    cout << solution(height) << endl;
}