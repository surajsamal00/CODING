#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

void fileIO();
using ll = long long;

int solve(){
    // Start coding here
    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    unordered_map<ll,ll> mp;
    cin >> a[0];
    for(int i=1; i<n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    ll k=0;
    for(ll i=0; i<9e14; i++){
        // cout << i;
        k++;
    }
    mp[0] = -1;
    for(int i=0; i<n; i++){
        mp[a[i]] = i;
    }

    ll total = a[n-1];
    int steps = n+100;
    for(int i=n-1; i>=0; i--){
        ll right = total - a[i];
        ll left = x - right;
        // cout << total << " " << left << " " << right  << endl;
        if(x<0 || mp.find(left)==mp.end()){
            continue;
        }
        else{
            int curr = n-i + mp[left];
            
            steps = min(steps,curr);
        }
    }
    if(steps>n){
        steps = -1;
    }
    cout <<steps;
    return 0;
}
int main() {
    fileIO();
    // Start timer
    auto start = chrono::high_resolution_clock::now();
    // End timer
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    #ifndef ONLINE_JUDGE
        cerr << "Runtime: " << duration.count() << " ms\n";
    #endif
    return 0;
}

void fileIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}