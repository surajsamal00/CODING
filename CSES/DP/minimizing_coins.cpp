#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }
    vector<int> dp(x+1, INT_MAX);
    dp[x] = 0;
    for(int i = x; i>0; i--){
        if(dp[i]==INT_MAX) continue;
        for(auto c : coins){
            int idx = i - c;
            if(idx >= 0){
                dp[idx] = min(dp[idx], dp[i]+1);
            }
        }
    }
    if(dp[0] == INT_MAX){
        dp[0] = -1;
    }
    cout << dp[0];
    return 0;
}
