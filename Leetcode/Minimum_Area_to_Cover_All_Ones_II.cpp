#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int area(int r1, int c1, int r2, int c2, vector<vector<int>>& grid) {
        int rmn = INT_MAX, rmx = INT_MIN, cmn = INT_MAX, cmx = INT_MIN;
        int cnt = 0;
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                if (grid[i][j]) {
                    cnt++;
                    rmn = min(rmn, i);
                    rmx = max(rmx, i);
                    cmn = min(cmn, j);
                    cmx = max(cmx, j);
                }
            }
        }
        if (cnt == 0)
            return 0;
        return ((rmx - rmn + 1) * (cmx - cmn + 1));
    }

    int splitter(int r1, int c1, int r2, int c2, int parts,
                 vector<vector<int>>& grid) {
        if (parts == 1) {
            return area(r1, c1, r2, c2, grid);
        }

        /*
        splitter func does one thing divide in k parts in best way possible 
        and return min area, and to do that ->
        horizontally and vertically you subdivide, lets say for 4:
        1 + 3, 2 + 2, 3 + 1 
        1 part means no more division so return min area required for coverage
        else recursively find different ways to subdivide further and take min from that;
        */
                        
        int mn = INT_MAX;
        // horizontal splits
        for (int i = r1; i < r2; i++) {
            for(int k = 1; k < parts; k++){
                 mn = min(mn, splitter(r1, c1, i, c2, k, grid) +
                             splitter(i + 1, c1, r2, c2, parts - k, grid));
            } 
            
        }

        // vertical splits
        for (int j = c1; j < c2; j++) {
            for(int k = 1; k < parts; k++){
                  mn = min(mn, splitter(r1, c1, r2, j, k, grid) +
                             splitter(r1, j + 1, r2, c2, parts - k, grid));
            }
        }

        return mn;
    }

    int minimumSum(vector<vector<int>>& grid) {
        int area = INT_MAX;
        int r1 = 0, r2 = grid.size() - 1, c1 = 0, c2 = grid[0].size() - 1;
        return splitter(r1, c1, r2, c2, 3, grid);
    }
};