#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n,-1));
    dp[0][0] = 3;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(dp[i][j]== 3) continue;
            else if(i == n - 1){
                dp[i][j] = 1;
            }
            else if(j == n - 1){
                dp[i][j] = 0;
            }
            else{
                if(a[i][j-1]<=a[i+1][j]){
                    dp[i][j-1] = 1;
                }
                if(a[i-1][j]<=a[i][j-1]){
                    dp[i-1][j] = 0;
                }
            }
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            cout << dp[n-1-i][n-1-j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    string ans = "";
    int i = 0, j = 0;
    while(i != n-1 || j != n-1) {
        ans += a[i][j];
        if(dp[i][j]==0){
            i++;
        }
        else{
            j++;
        }
    }
    cout << ans;
    return 0;
}
