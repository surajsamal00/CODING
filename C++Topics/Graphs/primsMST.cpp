#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;

//1584. Min Cost to Connect All Points
//Keep on adding the min edge you have in your edge cutting circle. 
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // visited and priority queue
        vector<bool> visited(n, false);
        priority_queue<pi , vector<pi>, greater<pi>> pq;


        int cost = 0;
        pq.push({0,0}); //donot mark visited here

        while(!pq.empty()){
            auto [d ,node] = pq.top();
            pq.pop();

            if(visited[node]){ //already visited by shorter edge (not path) so continue
                continue;
            }
            
            cost += d; //first time means this is the shortest edge to this node
            visited[node] = true;

            for(int i=0; i < n; i++){
                if(!visited[i]){ //donot mark visited here it will prevent shorter edges to be added later.
                    int cost_next = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                    pq.push({cost_next, i});
                }
            }
        }
        return cost;
    }
};

using pii = pair<int, int>;  // (weight, node)
int primMST(int n, vector<vector<pii>>& adj) {
    vector<bool> inMST(n, false);
    priority_queue<pii, vector<pii>, greater<>> pq;
    int totalCost = 0;

    pq.push({0, 0}); // Start from node 0, cost 0

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        totalCost += cost;

        for (auto [v, weight] : adj[u]) {
            if (!inMST[v]) {
                pq.push({weight, v});
            }
        }
    }

    return totalCost;
}

int main() {
    int n = 5;
    vector<vector<pii>> adj(n);

    // Example: Add edges
    // Edge: u - v with weight w
    vector<tuple<int, int, int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    for (auto [u, v, w] : edges) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    int mstCost = primMST(n, adj);
    cout << "Total cost of MST: " << mstCost << endl;
}
