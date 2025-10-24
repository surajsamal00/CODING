#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
 
 
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> pages(n),cost(n);
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }
 
    for(int i = 0; i < n; i++) {
        cin >> pages[i];
    }
 
    vector<int> dp(x+1,0);
    for(int i = n - 1; i >= 0; i--) {
        for(int j = x; j >= 0; j--){
            if(j - cost[i] >= 0){
                dp[j] = max(dp[j], pages[i] + dp[j - cost[i]]);
            }
        }
    }
    cout << dp[x];
 
    
    return 0;
}