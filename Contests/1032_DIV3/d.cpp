#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
#define MOD 1000000007


void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void fileIO(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w", stdout);
    #endif
}


//--------------------Workspace--------------------//
template<typename T>
void print(T a) { //vector only
    for (auto x:a){
        cout << x << " ";
        // cout << setw(11) <<x ;
    }
    cout << endl;
}

template<typename T>
void print2D(T a){
    for(auto x:a){
        for(auto y:x){
            cout << y << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

pair<int,int> search(int k, vector<vector<int>>&a){
    for(int i=0; i<2; i++){
        for(int j=0; j<a[0].size();j++){
            if(a[i][j]==k) return make_pair(i,j);
        }
    }
    return {-1,-1};
}
void test(){
    int n;
    cin >> n;
    vector<vector<int>> a(2,vector<int>(n));
    vector<vector<int>> steps;
    for(int i=0; i<n; i++){
        cin >> a[0][i];
    }
    for(int i=0; i<n; i++){
        cin >> a[1][i];
    }
    int k = 1;
    int poi = 0,poj=0; 
    // print2D(a);
    while(k<=n){
        auto [x, y] = search(k,a);
        
        if(y>poj){
            while(y!=poj){
                steps.push_back({x+1,y+1-1});
                swap(a[x][y],a[x][y-1]);
                y--;
            }
        }
        else if(y<poj){
            while(y!=poj){
                steps.push_back({x+1,y+1});
                swap(a[x][y],a[x][y+1]);
                y++;
            }
        }

        if(x==1){
            swap(a[0][y],a[1][y]);
            steps.push_back({3,y+1});

        }
        k++;
        poj++;
    }
    poi = 1, poj = 0;
    while(k<= 2*n){
        auto [x, y] = search(k,a);
        
        if(y>poj){
            while(y!=poj){
                steps.push_back({x+1,y+1-1});
                swap(a[x][y],a[x][y-1]);
                y--;
            }
        }
        else if(y<poj){
            while(y!=poj){
                steps.push_back({x+1,y+1});
                swap(a[x][y],a[x][y+1]);
                y++;
            }
        }
        k++;
        poj++;
    }
    // print2D(a);
    cout << steps.size() << endl;
    for(auto v:steps){
        cout << v[0] << " " << v[1] << endl;
    }
    // cout << endl;


}

signed main() {
    fastIO();
    fileIO();
    // Start timer
    auto start = chrono::high_resolution_clock::now();
    
    int tc = 1;
    cin >> tc;  //comment this if not needed
    while (tc--) {
        test();
    }

    // End timer
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    #ifndef ONLINE_JUDGE
        cerr << "Runtime: " << duration.count() << " ms\n";
    #endif
    return 0;
}
