#include <bits/stdc++.h>

using namespace std;
using pi = pair<int,int>;

class Solution {
public:
    //LCA Algo:
    vector<int> euler;
    vector<int> depth;
    vector<int> first;
    vector<int> seg;

    //Euler tour (with first seen and depth)
    void dfs(int node, int parent, int d, vector<vector<pi>>& adj){
        euler.push_back(node);
        first[node] = euler.size()-1;
        depth[node] = d;
        for(auto next:adj[node]){
            auto [nbr, w] = next;
            if(nbr==parent) continue;
            dfs(nbr, node, d+1, adj);
            euler.push_back(node);
        }
    }

    //segtree part on euler path which returns id of min depth node in range:
    void build(int node, int l, int r){
        if(l==r){
            seg[node] = euler[l];
            return;
        }

        int mid = (r+l)/2;

        build(2*node, l, mid);
        build(2*node+1, mid + 1, r);

        int left = seg[2*node], right = seg[2*node+1];
        seg[node] = (depth[left]<depth[right]) ? left:right;

    }

    int query(int node, int l, int r, int ql, int qr){
        if(l>qr || r<ql){
            return -1;
        } 
        if(ql<=l && r<= qr){
            return seg[node];
        }
        int mid = (r+l)/2;
        int left = query(2*node, l, mid, ql, qr);
        int right = query(2*node+1, mid+1, r, ql, qr);

        // if(left==-1 && right==-1){ //adjusted in no overlap
        //     return -1; 
        // }
        if(left==-1){
            return right;
        }
        else if(right==-1){
            return left;
        }
        else{
            return (depth[left]<depth[right]) ? left : right;
        }
    }

    // Question specific (LEETCODE: 2846. Minimum Edge Weight Equilibrium Queries in a Tree)
    vector<vector<int>> freq;
    void travel(int node, int parent, vector<int>& curr, vector<vector<pi>>& adj){
        freq[node] = curr;
        for(auto next : adj[node]){
            auto [nbr, w] = next;
            if(nbr==parent) continue;
            curr[w]+=1;
            travel(nbr,node,curr,adj);
            curr[w]-=1;
        }
    }

    void print(vector<int> a){
        for(auto x:a) cout << x << " ";
        cout << endl;
    }

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        freq.assign(n+1, vector<int>());
        depth.assign(n,-1);
        first.assign(n,-1);
        vector<vector<pair<int,int>>> adj(n+1);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> curr(30,0);
        travel(0,-1,curr,adj);
        
        dfs(0, -1, 0, adj);
        
        cout << "Euler Path:\n";
        print(euler);

        cout << "First idx:\n";
        print(first);

        cout << "Depth from root:\n";
        print(depth);

        int sz = euler.size();
        seg.assign(4*sz,0);
        build(1,0,euler.size()-1);
        vector<int> ans;
        for(auto& q:queries){
            int u = first[q[0]], v = first[q[1]];
            if(u>v){
                swap(u,v);
            }

            int lca = query(1,0,euler.size()-1,u,v);

            vector<int> dist(30,0);
            int sum = 0;
            int maxi = 0;
            for(int i=0; i<30; i++){
                dist[i] = freq[q[0]][i] + freq[q[1]][i] - 2*freq[lca][i];
                sum += dist[i];
                maxi = max(dist[i],maxi);
            }
            ans.push_back(sum-maxi);
        }
        return ans;

        
    }
};

int main(){
    int n = 8;
    vector<vector<int>> edges = {
        {1, 2, 6},
        {1, 3, 4},
        {2, 4, 6},
        {2, 5, 3},
        {3, 6, 6},
        {3, 0, 8},
        {7, 0, 2}
    };
    vector<vector<int>>  queries = {
        {4, 6},
        {0, 4},
        {6, 5},
        {7, 4}
    };

    Solution obj = Solution();
    vector<int> ans = obj.minOperationsQueries(n,edges,queries);
    cout << "\nSolution:\n";
    for(auto x:ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}