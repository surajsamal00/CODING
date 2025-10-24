#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1e9+7;
//Div 4 918 F
void solve(){
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vector<pair<int,int>> a(n);
        set<int> starts;
        for(int i=0; i<n; i++){
            cin >> a[i].second;
            cin >> a[i].first;
        }
        sort(a.begin(), a.end());
        
        //coordinate compression:
        vector<int> ys;
        for(int i=0; i<n; i++) {
            ys.push_back(a[i].second);
        }
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        for (auto& [x, y] : a){
            y = lower_bound(ys.begin(), ys.end(), y) - ys.begin() + 1; //for 1 based fenwick
        }
        
        int m = ys.size();


        //fenwick on the fly;
        vector<int> tree(m+2,0);
        auto lowbit = [](int i){
            return (i & (-i));
        };

        auto update = [&](int i, int val){
            while(i<tree.size()){
                tree[i] += val;
                i += lowbit(i);
            }
        };

        auto sum = [&](int i){
            int res = 0;
            while(i>0){
                res += tree[i];
                i -= lowbit(i);  
            }
            return res;
        };

        
        int handshakes = 0;
        for(int i=0; i<n; i++){
            int end = a[i].first;
            int start = a[i].second;
            handshakes += sum(m) - sum(start);
            update(start, 1);
        }
        cout << handshakes << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    solve();
    return 0;
}