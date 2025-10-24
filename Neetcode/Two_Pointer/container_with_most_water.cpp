#include <bits/stdc++.h>
using namespace std;

// 11. Container With Most Water 
// https://leetcode.com/problems/container-with-most-water/description/

/*
This is a greedy method better to watch on youtube
Basically start from two ends and always decrease the smaller height 
because changing the larger one will never give better as width is 
decreasing and even if you find larger column inside the height will
still be the min of two so width decreased with no improvement.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while(l < r) {
            ans = max(ans, (r - l) * min(height[l], height[r]));
            if(height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return ans;
    }
};