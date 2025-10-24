#include<bits/stdc++.h>
using namespace std;

/*
🧠 Key Idea:
To get MST, greedily add the shortest edges first, while avoiding cycles, until all nodes are connected.

🛠️ Steps:
Sort all edges in increasing order of weight.
Initialize DSU (Disjoint Set Union) to track connected components.
For each edge (u, v) in sorted order:
If u and v are in different components, add the edge to MST and union them.
Stop when MST has n - 1 edges (for n nodes).

⚙️ Data Structures Used:
DSU (Union-Find) with:
Path compression (findParent)
Union by rank or size

🕒 Time Complexity:
Sorting edges: O(E log E)
Union-Find: O(α(N)) per operation (almost constant with path compression)
Overall: O(E log E)

✅ When to Use:
When edge list is already available or the graph is sparse
Very useful in offline or static graph problems
*/

class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    void initiate(int N){
        rank.assign(N+1, 1);
        parent.assign(N+1,0);
        iota(parent.begin(), parent.end(), 0);

    }
    int findParent(int u){
        if(parent[u] == u) return u;
        else return parent[u] = findParent(parent[u]);
    }

    bool unionByRank(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v) return false;
        if(rank[ulp_u] == rank[ulp_v]){
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_u] = ulp_v;
        }
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i , j});
            }
        }
        sort(edges.begin(), edges.end());
        int n = points.size();
        initiate(n);

        int cost = 0;
        int edge_cnt = 0;
        for(int i = 0; i < edges.size(); i++) {
            int x = edges[i][1], y = edges[i][2], val = edges[i][0];
            if(unionByRank(x, y)){
                cost += val;

                edge_cnt++;
                if(edge_cnt == n-1){ // tree complete
                    break;
                }
            }
        }

        return cost;
    }
};

int main(){
    return 0;
}