#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

struct DSU{
    int N;
    vector<int> parent, size;
    DSU(int n) : N(n), parent(n+1), size(n+1,1){
        iota(parent.begin(), parent.end(),0);
    }

    int findParent(int u){
        if(parent[u] == u) return u;
        else return parent[u] = findParent(parent[u]);
    }

    void unionSize(int u, int v){
        int pu = findParent(u), pv = findParent(v);
        if(pu == pv) return;
        else if(size[pu] >= size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

signed main() {
    int n, m, u, v;
    cin >> n >> m;
    DSU dsu = DSU(n);
    int comp = n;
    multiset<int, greater<int>> ms;
    map<int, int> mp;
    for(int i = 1; i <= n; i++){
        ms.insert(1);
        mp[i] = 1;
    }
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        int pu = dsu.findParent(u), pv = dsu.findParent(v);
        if(pu != pv){
            comp -= 1;
            
            if(dsu.size[pu] >= dsu.size[pv]){
                int su = mp[pu], sv = mp[pv];
                
                if(auto itr = ms.find(sv); itr != ms.end())
                    ms.erase(itr);

                if(auto itr = ms.find(su); itr != ms.end())
                    ms.erase(itr);

                mp.erase(pv);
                mp[pu] += sv;
                ms.insert(mp[pu]);
                
            }
            else{
                int su = mp[pu], sv = mp[pv];

                if(auto itr = ms.find(sv); itr != ms.end())
                    ms.erase(itr);

                if(auto itr = ms.find(su); itr != ms.end())
                    ms.erase(itr);

                mp.erase(pu);
                mp[pv] += su;
                ms.insert(mp[pv]);
            }
            dsu.unionSize(pu, pv);
        }

        cout << comp << " " << *ms.begin() << endl;

    }
    
    return 0;
}
