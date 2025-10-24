#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define int long long
using tiii = tuple<int, int, int>;


struct comp {
    bool operator()(const tiii& a, const tiii& b ) const {
        return get<0>(a) < get<0>(b);
    }
};

signed main(){
    int n;
    cin >> n;
    vector<tuple<int,int,int>> a(n);
    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = {x, y, z};
    }

    sort(a.begin(), a.end());
    vector<int> dp(n,0);
    for(int i = n - 1; i >= 0; i--){
        auto [s, e, p] = a[i];
        int x = 0, y = p;
        if(i+1 < n) {
            x = dp[i+1];
        }
        int j = upper_bound(a.begin()+i+1, a.end(), make_tuple(e,INT_MAX,INT_MAX), comp()) - a.begin();
        if(j != n){
            y += dp[j];
        }
        dp[i] = max(x, y);
    }

    cout << dp[0];
    return 0;

}