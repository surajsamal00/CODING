#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static constexpr int N=1e5+5;  //big value
int up[N][26];      // ~1e7
int depth[N];
vector<vector<int>> adj;

void dfs(int u, int p){
    up[u][0] = p; // (2^0) 1 up is parent

    for(int i=1; i<26; i++){
        if(up[u][i-1]!=-1){
            up[u][i] = up[up[u][i-1]][i-1];
        }
        else{
            up[u][i] = -1;
        }
    }

    for(auto next: adj[u]){
        if(next==p) continue;
        else{
            depth[next] = 1 + depth[u];
            dfs(next,u);
        }
    }
}

int lift(int u, int k){
    for(int i=0; i<25; i++){ // can deduct from either way jump set remains same;
        if(k & (1<<i)){
            u = up[u][i]; // i is the bit position up[N][26]
            if(u==-1) break;
        }
    }
    return u;
}

int main() {
    int n = 9;
    vector<pair<int, int>> edges = {
        {1, 2}, {1, 3}, {1, 4}, {2, 5},
        {2, 6}, {6, 8}, {8, 9}, {4, 7}
    };

    adj.assign(n+1,vector<int>(0)); //one based nodes
    for(auto [u, v]:edges){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(up,-1,sizeof(up));
    depth[1] = 0;
    dfs(1,-1);
    cout << lift(7,3);
    return 0;
}

// for(int i=0; i<10; i++){
//     for(int j=0; j<20; j++){
//         cout << up[i][j] << " ";
//     }
//     cout << endl;
// }