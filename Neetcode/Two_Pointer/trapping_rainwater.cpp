#include <bits/stdc++.h>
using namespace std;

// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/description/
class Solution {
public:
    int trap(vector<int>& height) {
        /*
        stand on a column now after raining how much water will be in
        this 1 unit width column. It's basically the the minimum of the 
        two certain columns.. first one is the maximum among the left side
        and second is the max among the right side. Now that's the water level 
        current column will fill (or maybe not in case the column is higher only
        solid metal will be there instead of water). Can do easily in O(n^2) but 
        here we use special monotonic stack;
        */

        vector<int> left(height.size(), 0);
        int lmax = height[0];
        for(int i = 1; i < height.size(); i++) { // first guy has no left side
            left[i] = lmax;
            lmax = max(height[i], lmax);
        }

        vector<int> right(height.size(), 0);
        int rmax = height.back();
        for(int i = height.size() - 2; i >= 0; i--) { // last guy has no right side
            right[i] = rmax;
            rmax = max(height[i], rmax);
        }


        //Now find the min water column height compare it with solid column and add to total;
        int total = 0;
        for(int i = 0; i < height.size(); i++) {
            int water_col = min(left[i], right[i]);
            total += max(0, water_col - height[i]);
        }

        return total;
    }
};