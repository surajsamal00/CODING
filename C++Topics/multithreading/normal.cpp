#include<bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Start timer
    auto start = chrono::high_resolution_clock::now();
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t, n, q;
    t = 1;
    cin >> t;
    while(t--) {
        cin >> n >> q;
        vector<int> a(n+1,0);
        a[0] = -1;
        vector<int> pre_z(n+1,0), pre_o(n+1,0);
        
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i]==0){
                pre_z[i] = 1;
            }
            else{
                pre_o[i] = 1;
            }
            pre_z[i] += pre_z[i-1];
            pre_o[i] += pre_o[i-1];
        }
        vector<int> same(n+2, 0);
        for(int i = 2; i <= n; i++) {
            same[i] += same[i-1];
            if(a[i] == a[i-1]) {
                same[i] += 1;
            }
        }
        int l, r;
        while(q--) {
            cin >> l >> r;
            if((pre_z[r] - pre_z[l-1])%3 != 0 || (pre_o[r] - pre_o[l-1])%3 != 0) {
                cout << -1 << endl;
                continue;
            }
            int extra = 0;
            if(same[r] == same[l-1]) extra = 1;
            else if(same[r] == (same[l-1] + 1) && a[l]==a[l-1]) extra++;
            cout << (pre_z[r] - pre_z[l-1])/3 + (pre_o[r] - pre_o[l-1])/3 + extra << endl;
        }
    }
    // End timer
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    #ifndef ONLINE_JUDGE
        cerr << "Runtime: " << duration.count() << " ms\n";
    #endif
    return 0;
}