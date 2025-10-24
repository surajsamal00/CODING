#include <bits/stdc++.h>
using namespace std;
 
template<typename T>
void print(T a) { 
    for (auto x:a){
        cout << x << " ";
    }
    cout << endl;
}
 
int up[200009][32];

int lift(int node, int k){
    for(int i = 0; (i <= 30) && (node != -1); i++){
        if(k&(1LL<<i)){
            node = up[node][i];
        }
    }
    return node;
}
 
void print(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 30; j++){
            cout<< up[i][j] <<  " ";
        }
        cout << endl;
    }
}
vector<int> visited;
void process(int i, int id, vector<int>& adj, vector<int>& comp, vector<int>& pos, 
                vector<int>& depth, vector<int>&len){
    
    int slow = i, fast = i;
    do{
        visited[slow] = 1;
        slow = adj[slow];
        fast = adj[adj[fast]];
    } while(slow != fast);
    slow = i;
    while(slow != fast){
        slow = adj[slow];
        fast = adj[fast];
    }
    int cnt = 0;
    int entry_point = slow;
    do{
        visited[slow] = 1;
        pos[slow] = cnt;
        comp[slow] = id;
        cnt += 1;
        slow = adj[slow];
    } while(slow != entry_point);
    len.push_back(cnt);
    int d = 0;
    
}
void test_case(){
    int n, q, p;
    cin >> n >> q;
    memset(up, -1, sizeof(up));
    vector<int> adj(n+1,-1);
    visited.assign(n+1,0);
    
    //build first step
    for(int i = 1; i <= n; i++){
        cin >> p;
        up[i][0] = p;
        adj[i] = p;
    }
    
 
    //build rest;
    for(int level = 1; level <= 30; level++){
        for(int node = 1; node <= n; node++){
            if(up[node][level-1] != -1){
                up[node][level] = up[ up[node][level-1] ][level-1];
            }
            else{
                up[node][level] = -1;
            }
            
        }
    }
    
    vector<int> comp(n+1,-1);
    vector<int> pos(n+1, -1);
    vector<int> depth(n+1,-1);
    vector<int> len;
    int id = -1;
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            id++;
            process(i, id, adj, comp, pos, depth, len);
        }
    }
    
 
    while(q--){
        int node, k;
        cin >> node >> k;
        cout << lift(node, k) << endl;
    }
    
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