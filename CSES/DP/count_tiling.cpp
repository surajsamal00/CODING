#include <bits/stdc++.h>
using namespace std;
// #define int long long
int mod = 1e9 + 7;


vector<vector<int>> dp;

void calc(int i, int mask, int n, vector<int>& arr){
    if(i == n){
        arr.push_back(mask);
        return;
    }

    int curr = mask&(1LL<<i);
    int next = mask&(1LL<<(i+1));
    if(curr == 0){
        if(i<n-1 && next == 0){
            calc(i+2, mask, n, arr);
        }
        calc(i+1, (mask|(1LL<<i)), n, arr);
    }
    else{
        mask = mask & ~(1LL<<i);
        calc(i+1,mask, n, arr);
    }
}


int solve(int row, int mask, int m, int n){
    if(row == m) {
        return (mask == 0);
    }

    if(dp[row][mask]!= -1){
        return dp[row][mask];
    }

    vector<int> arr;
    calc(0, mask, n, arr);
    int ans = 0;
    for(auto msk : arr){
        ans += solve(row+1, msk, m, n);
        ans %= mod;
    }
    return dp[row][mask] = ans;
}

signed main() {
    int n, m;
    cin >> n >> m;
    if(n>m) swap(n, m);
    dp.assign(m+1,vector<int>(1<<n, -1));
    cout << solve(0,0,m,n);
    return 0;
}


/*

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9+7;

int n, m;
vector<vector<int>> transitions;

// generate valid transitions from a mask in one row to next row
void calc(int i, int mask, int n, int newMask, vector<int>& arr) {
    if(i == n) {
        arr.push_back(newMask);
        return;
    }
    if(mask & (1<<i)) {
        // cell already filled, skip
        calc(i+1, mask, n, newMask, arr);
    } else {
        // place vertical domino
        calc(i+1, mask, n, newMask | (1<<i), arr);
        // place horizontal domino if possible
        if(i+1 < n && !(mask & (1<<(i+1)))) {
            calc(i+2, mask, n, newMask, arr);
        }
    }
}

signed main() {
    cin >> n >> m;
    if(n > m) swap(n, m);

    int maxMask = 1<<n;
    transitions.resize(maxMask);

    // precompute all possible next masks for each current mask
    for(int mask=0; mask<maxMask; mask++) {
        vector<int> arr;
        calc(0, mask, n, 0, arr);
        transitions[mask] = arr;
    }

    // DP table: dp[row][mask]
    vector<vector<int>> dp(m+1, vector<int>(maxMask, 0));
    dp[0][0] = 1;

    for(int row=0; row<m; row++) {
        for(int mask=0; mask<maxMask; mask++) {
            if(dp[row][mask] == 0) continue;
            for(int nxt : transitions[mask]) {
                dp[row+1][nxt] = (dp[row+1][nxt] + dp[row][mask]) % mod;
            }
        }
    }

    cout << dp[m][0] << "\n";
    return 0;
}
*/