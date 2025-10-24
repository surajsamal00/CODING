#include<bits/stdc++.h>
using namespace std;

void iterativeDFS(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    stack<int> stk;

    stk.push(start);

    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();

        if (visited[node]) continue;
        visited[node] = true;

        cout << node << " ";

        // Push neighbors in reverse order for same order as recursive DFS
        for (int i = adj[node].size() - 1; i >= 0; i--) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                stk.push(neighbor);
            }
        }
    }
}

int main(){
    int n = 6;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {4, 5};

    // DFS starting from 0
    iterativeDFS(0, adj, n);

    return 0;
}
