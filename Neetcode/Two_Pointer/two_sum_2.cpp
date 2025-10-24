#include <bits/stdc++.h>
using namespace std;
// 167. Two Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/


/*
Basically greedy sort the array start from the two ends with 'l' and 'r'.
if sum of l and r is less increase l, if sum is more than required decrease r.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                return {l+1, r+1}; // 1 - based
            } 
            else if (sum < target) {
                l++;
            } 
            else{ 
                r--; 
            }
        }
        return {-1, -1}; // not found
    }
};