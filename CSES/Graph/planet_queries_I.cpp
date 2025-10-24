#include <bits/stdc++.h>
using namespace std;

//long long tle issue(compiler based)
 
template<typename T>
void print(T a) { 
    for (auto x:a){
        cout << x << " ";
    }
    cout << endl;
}
 
int up[200009][30];

int lift(int node, int k){
    for(int i = 0; (i < 30) && (node != -1); i++){
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
void test_case(){
    int n, q, p;
    cin >> n >> q;
    memset(up, -1, sizeof(up));
 
    
    //build first step
    for(int i = 1; i <= n; i++){
        cin >> p;
        up[i][0] = p;
        
    }
    
    
 
    //build rest;
    for(int level = 1; level < 30; level++){
        for(int node = 1; node <= n; node++){
            if(up[node][level-1] != -1){
                up[node][level] = up[ up[node][level-1] ][level-1];
            }
            else{
                up[node][level] = -1;
            }
            
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