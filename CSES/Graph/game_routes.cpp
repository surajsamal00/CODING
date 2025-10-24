#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int inf = 1e18;

template<typename T>
void print(T a) { 
    for (auto x:a){
        cout << x << " ";
    }
    cout << endl;
}

int dfs(int node, vector<int>& dp, vector<vector<int>>& adj){
    if(dp[node] != -1){
        return dp[node];
    }
    int ans = 0;
    for(auto nbr : adj[node]){
        ans = (ans + dfs(nbr, dp, adj)) % mod;
    }
    return dp[node] = ans;
}
void test_case(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> dp(n+1, -1);
    dp[n] = 1;
    int ans = dfs(1, dp, adj);
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    while(T--){
        test_case();
    }
    return 0;
}