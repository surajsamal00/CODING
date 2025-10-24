#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int j = 0; j < m; j++) {
        cin >> b[j];
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            if(a[i] == b[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    cout << dp[0][0] << endl;

    int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] == b[j]){
            cout << a[i] << " ";
            i++;
            j++;
        }
        else if(dp[i+1][j] >= dp[i][j+1]){ 
            //extra row and cols with zero padding
            //don't worry you won't run out
            i++;
        }
        else{
            j++;
        }
    }
    cout << endl;

    return 0;
}