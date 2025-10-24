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


void test(){
    int w,h,a,b;
    cin >> w >> h >> a >> b;

    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    if((x1-x2)%a!=0 && (y1-y2)%b!=0){
        cout << "NO\n";
        return;
    }
    else if((x1-x2)%a!=0 && y1==y2){
        cout << "NO\n";
        return;
    }
    else if((y1-y2)%b!=0 && x1==x2){
        cout << "NO\n";
        return;
    }
    else{
        cout << "YES\n";
        return;
    }

    // bool flg = true;
    // //x direction
    // if()



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


