#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> prefix(n+1, 0);
    prefix[0] = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        prefix[i+1] += a[i] + prefix[i];
    }
    vector<vector<int>> dp(n, vector<int>(n,0));
    for(int i = n-1; i >= 0; i--) {
        dp[i][i] = a[i];
        for(int j = i + 1; j < n; j++) {
            int x = a[i] + prefix[j+1] - prefix[i+1] - dp[i+1][j];
            int y = a[j] + prefix[j] - prefix[i] - dp[i][j-1];
            dp[i][j] = max(x, y);
        }
    }
    cout << dp[0][n-1];
    return 0;
}
