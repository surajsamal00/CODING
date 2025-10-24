#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;


int main() {
    int n;
    cin >> n;
    vector<string> grid(n);

    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<int> dp(n+1, 0);
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--){          
            if(grid[i][j] == '*'){
                dp[j] = 0;
            }
            else if(i == n - 1 && j == n - 1){
                dp[j] = 1;
            }
            else{
                dp[j] += dp[j+1];
                dp[j] %= mod;
            }
        }
        dp[n] = 0;
    }
    cout << dp[0];
    return 0;
}
