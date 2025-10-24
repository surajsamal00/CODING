#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int parent[100007];
int rnk[100007];

int findParent(int u){
    if(parent[u]==u) return u;
    else return parent[u] = findParent(parent[u]);
}

void unionByRank(int u, int v){
    int pu = findParent(u);
    int pv = findParent(v);
    if(pu == pv) return;
    if(rnk[pu] == rnk[pv]){
        parent[pv] = pu;
        rnk[pu]++;
    }
    else if(rnk[pu] > rnk[pv]){
        parent[pv] = pu;
    }
    else{
        parent[pu] = pv;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++){
        parent[i] = i;
        rnk[i] = 1;
    }

    vector<vector<int>> roads;
    while(m--){
        int u, v;
        cin >> u >> v;
        unionByRank(u, v);
    }
    for(int i = 1; i < n; i++){
        int pu = findParent(i);
        int pv = findParent(i+1);
        if(pu == pv) {
            continue;
        }
        else{
            roads.push_back({pu, pv});
            unionByRank(pu, pv);
        }
    }
    cout << roads.size() << endl;
    for(auto v : roads){
        cout << v[0] << " " << v[1] << "\n";
    }

    return 0;
}