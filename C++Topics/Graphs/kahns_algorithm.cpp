#include<bits/stdc++.h>
using namespace std;

/*
🔧 Kahn’s Algorithm Steps:
Calculate in-degree of all nodes.
Push all nodes with in-degree 0 into a queue.
While the queue is not empty:
Pop a node u
Add u to the topological ordering
For each neighbor v of u, decrement in-degree[v]
If in-degree[v] becomes 0, add v to the queue.
You don't need to worry about child considering parent (its directed);
If the topological ordering has fewer nodes than N, there's a cycle.

📦 Time and Space Complexity:
Time: O(V + E)
Space: O(V)

postorder dfs and reversal is also one method.
*/

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
}