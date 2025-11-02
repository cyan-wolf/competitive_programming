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

// Accepted

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int>& height) {
    int lptr = 0;
    int rptr = height.size() - 1;
    int max_area = 0;

    while (lptr <= rptr) {
        int dx = rptr - lptr;
        int dy = min(height[lptr], height[rptr]);
        int area = dx * dy;

        // Keep updating the max area.
        if (area > max_area) {
            max_area = area;
        }

        // Always move the smallest container edge (move the left one
        // as a tie-breaker).
        if (height.at(lptr) < height.at(rptr)) {
            lptr++;
        }
        else {
            rptr--;
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
    vector<int> height = {1,8,6,2,5,4,8,3,7};   // 49
    cout << solution(height) << endl;

    height = {1,1};                             // 1
    cout << solution(height) << endl;

    height = {2,3,4,5,18,17,6};                 // 17
    cout << solution(height) << endl;
}