#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n+1,vector<int>(m+2,0));
    vector<int> a(n+1,0);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    if(a[1]==0){
        for(int i = 1; i<=m; i++){
            dp[1][i] = 1;
        }
    }
    else{
        dp[1][a[1]] = 1;
    }

    for(int i = 2; i <= n; i++){
        if(a[i] == 0){
            for(int j = 1; j<=m; j++){
                dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j])%mod + dp[i-1][j+1]) % mod;
            }
        }
        else{
            int j = a[i];
            dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j])%mod + dp[i-1][j+1]) % mod;
        }
    }

    int sum = 0;
    for(int i=0; i<=m; i++){
        sum = (sum + dp[n][i]) % mod;
    }
    cout << sum;
    
    return 0;
}
