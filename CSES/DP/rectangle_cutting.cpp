#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

vector<vector<int>> dp;


int main() {
    int n, m;
    cin >> n >> m;
    dp.assign(n+1, vector<int>(m+1,INT_MAX));

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(i==j) dp[i][j] = 0;
            else if(j<=n && i<=m && dp[j][i] != INT_MAX){ // if possible to fit transpose in matrix
                dp[i][j] = dp[j][i];
            }
            else{
                //horizontal:
                for(int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
                }

                //vertical:
                for(int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
                }

            }
        }
    }
    cout << dp[n][m];
    return 0;
}
