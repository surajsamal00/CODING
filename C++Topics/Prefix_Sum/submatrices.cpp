#include <bits/stdc++.h>
using namespace std;
/*
//#1074. Number of Submatrices That Sum to Target
Using a 2D prefix sum, we can query the sum of any submatrix in O(1) time. 
Now for each (r1, r2), we can find the largest sum of a submatrix that uses 
every row in [r1, r2] in linear time using a sliding window.
*/

int prefix[101][101];
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        //2D prefix_sum
        int m = matrix.size(), n = matrix[0].size();
        memset(prefix,0,sizeof(prefix));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int ni = i + 1, nj = j + 1;
                prefix[ni][nj] = matrix[i][j] + prefix[ni - 1][nj] +
                                 prefix[ni][nj - 1] - prefix[ni - 1][nj - 1];
            }
        }

        int ans = 0;
        for (int r1 = 0; r1 < m; r1++) {
            for (int r2 = r1; r2 < m; r2++) {
                // The counting part
                unordered_map<int, int> freq;
                freq[0] = 1;
                int cnt = 0;
                for (int j = 1; j <= n; j++) {
                    int area = prefix[r2 + 1][j] + prefix[r1][0] -
                               prefix[r1][j] - prefix[r2 + 1][0];
                    int req = area - target;
                    cnt += freq[req];
                    freq[area] += 1;
                }
                ans += cnt;
            }
        }
        return ans;
    }
};