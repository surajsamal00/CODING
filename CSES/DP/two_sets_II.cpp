#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
 
void print(vector<int> a){
    for(auto x : a){
        cout << setw(4) << x << " ";
    }
    cout << endl;
}

long long mod_pow(long long a, long long b, int mod){
    int res = 1;
    while(b>0){
        if(b&1){
            res = (res*a)%mod;
        }
        b>>=1;
        a = (a*a)%mod;
    }
    return res;
}
 
int main() {
    int n;
    cin >> n;
    int total = (n*(n+1))/2;
    if(total&1) {
        cout << 0;
    }
    else {
        total /= 2;
        vector<int> dp(total + 1, 0);
        dp[0] = 1;
        // print(dp);
        for(int i = n; i > 0; i--) {
            for(int j = total; j >= i; j--){
                dp[j] += dp[j - i];
                dp[j] %= mod;
            }
            // print(dp);
        }
        int ans  = (dp[total] * mod_pow(2, mod-2,mod)) % mod;
        cout << ans;
    }
    return 0;
}