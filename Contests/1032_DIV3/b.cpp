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
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool flg = false;
    vector<int> mp(26,0);
    mp[s[0]-'a'] = 1;
    mp[s[n-1]-'a'] = 1;

    for(int i=1;i<n-1;i++){
        if(mp[s[i]-'a']>0) flg=true;
        mp[s[i]-'a'] = 1;
    }
    if(flg){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

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
