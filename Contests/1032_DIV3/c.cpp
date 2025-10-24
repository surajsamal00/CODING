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

int calculate(int r_max, int c_max, vector<vector<int>>& a){
    int ans = 0;
    int n = a.size()-1, m = a[0].size()-1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==r_max || j==c_max){
                ans = max(ans, a[i][j]-1);
            }
            else{
                ans = max(ans, a[i][j]);
            }
        }
    }
    return ans;
}

void test(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    int maxi = 0;
    int cnt = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
            maxi = max(maxi,a[i][j]);
        }
    }
    int r,c;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j]==maxi){
                r = i;
                c = j;
                goto next;
            }
        }
    }
    next:

    //if row is correct:
    int ans = maxi;
    bool flg = true;
    int temp = 0;
    for(int i=1; i<=n && flg; i++){
        if(i==r) continue;
        for(int j=1; j<=m && flg; j++){
            if(a[i][j]==maxi){
                flg = false;
                temp = j;
            }
        }
    }

    ans = min(ans,calculate(r,temp,a));

    //if col is correct;
    flg = true;
    for(int i=1; i<=n && flg; i++){
        for(int j=1; j<=m && flg; j++){
            if(j==c) continue;
            if(a[i][j]==maxi){
                flg = false;
                temp = i;
            }
        }
    }
    ans = min(ans,calculate(temp,c,a));


    cout << ans << endl;
    
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
