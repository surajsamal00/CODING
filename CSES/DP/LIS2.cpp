#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;


signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> coords;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        coords.push_back(a[i]);
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    
    for(int i = 0; i < n; i++){
        int idx = lower_bound(coords.begin(), coords.end(), a[i]) - coords.begin() + 1;
        a[i] = idx;
    }
    
    int m = coords.size();

    vector<int> fen(m+2,0);
    auto low_bit = [](int i){
        return (i & (-i));
    };

    auto update = [&](int i, int val){
        while(i < fen.size()){
            fen[i] += val;
            fen[i] %= mod;
            i += low_bit(i);
        }
    };

    auto sum = [&](int i){
        int res = 0;
        while(i>0){
            res += fen[i];
            res %= mod;
            i -= low_bit(i);
        }
        return res;
    };

    vector<int> dp(n, 0);
    for(int i = 0; i < n; i++){
        int pos = a[i];
        dp[i] = (sum(pos-1) + 1)%mod;
        update(pos, dp[i]);
    }

    cout << sum(m); //total prefix sum
    return 0;
}