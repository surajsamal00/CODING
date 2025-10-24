#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }

    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for(int i = 0; i<x; i++){
        if(dp[i]== 0) continue;
        for(auto c : coins){
            int idx = i + c;
            if(idx <= x){
                dp[idx] = (dp[idx] + dp[i])%mod;
            }
        }
    }

    cout << dp[x];
    return 0;
}
