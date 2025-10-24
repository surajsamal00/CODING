#include <bits/stdc++.h>

using namespace std;
using ll = long long;
// #define int long long

ll mod = 1e9+7;


void solve(){
    int t=1;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
            if(a[i]==0){
                a[i] = 1;
            }
        }
        int sum = accumulate(a.begin(), a.end(), 0);
        cout << sum << endl;
        
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}