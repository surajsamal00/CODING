#include <bits/stdc++.h>
using namespace std;
// Good way to start from the end to find the len.
// to find the string start from start and move accordingly.
class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int m = a.size(), n = b.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if(a[i] == b[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        int l = 0, r = 0;
        string lcs = "";
        while(l < m && r < n) {
            if(a[l] == b[r]) {
                lcs += a[l];
                l++;
                r++;
            }
            else if(dp[l][r+1] > dp[l+1][r]) {
                r++;
            }
            else {
                l++;
            }
        }
        cout << lcs;
        return dp[0][0];
    }
};