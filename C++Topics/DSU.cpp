#include <bits/stdc++.h>
using namespace std;


class DisjointSet{
public:
    int N;
    vector<int> parent, rank, size;
    DisjointSet(int n) : N(n), parent(n+1,1), rank(n+1,1), size(n+1,1){
        iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int node){
        if(parent[node]==node) return node;
        else return parent[node]=findParent(parent[node]);
    }

    void unionByRank(int u, int v){  //modify union logic based on question
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u==ulp_v){
            return;
        }
        else{
            if(rank[ulp_u]>rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u] += 1;
            }
        }
    }

    void unionBySize(int u, int v){  //modify union logic based on question
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u==ulp_v){
            return;
        }
        else{
            if(size[ulp_u]>=size[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];

            }
            else{
                parent[ulp_u] = ulp_v;
                rank[ulp_v] += size[ulp_u];
            }
        }
    }
};

int main(){
    //Leetcode 1061. Lexicographically Smallest Equivalent String
    string s1="parker", s2="morris", baseStr="parser";

    DisjointSet eqv = DisjointSet(26);

    for(int i=1; i<=26; i++){
        eqv.rank[i] = 26-i+1;
    }

    for(int i=0; i<s1.size(); i++){
        int val1 = (s1[i]-'a'+1);
        int val2 = (s2[i]-'a'+1);
        eqv.unionByRank(val1, val2);
    }

    for(int i=0; i<baseStr.size();i++){
        baseStr[i] = ( (eqv.findParent((baseStr[i]-'a'+1)) - 1) + 'a');
    }
    cout << baseStr;
    return 0;
}

/*
//Shorter Practical Size based

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

*/