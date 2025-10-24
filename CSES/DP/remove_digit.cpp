#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;


int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1,1e9);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        int num = i;
        while(num > 0){
            int k = num%10;
            num /= 10;
            dp[i] = min(dp[i], 1 + dp[i-k]);
        }
    }
    cout << dp[n];
    return 0;
}
