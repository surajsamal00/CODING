#include <bits/stdc++.h>
using namespace std;

// 15. 3Sum
// https://leetcode.com/problems/3sum/description/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        // {a, b, c} with a + b + c  = 0 -> two sum with b + c = -a
        for(int i = 0; i < nums.size(); i++) {
            if(i != 0 && nums[i] == nums[i-1]) continue; // deals with duplicates in first element
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                if(l > i + 1 && nums[l] == nums[l-1]){ // deals second element
                    l++;
                    continue;
                }
                int sum = nums[l] + nums[r];
                if(sum == target) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                }
                else if(sum > target) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return ans;
    }
};