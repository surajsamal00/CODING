#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

vector<int> dp;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());

    dp.assign(x+1,0);
    
    for(auto c : coins){
        dp[0] = 1;
        for(int cost = c; cost <= x; cost++){
            dp[cost] += dp[cost - c];
            dp[cost] %= mod;
        }
    }

    cout << dp[x];
    return 0;
}
