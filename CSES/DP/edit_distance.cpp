#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;


int main() {
    string a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1,0));

    for(int i = 0; i <= a.size(); i++){
        dp[i][b.size()] = a.size() - i;
    }

    for(int j = 0; j <= b.size(); j++){
        dp[a.size()][j] = b.size() - j;
    }

    for(int i = a.size() - 1; i >= 0; i--) {
        for(int j = b.size() - 1; j >= 0; j--) {
            if(a[i] == b[j]){
                dp[i][j] = dp[i+1][j+1];
            }
            else{
                dp[i][j] = 1 + min(dp[i+1][j+1], min(dp[i][j+1], dp[i+1][j]));
            }
        }
    }
    cout << dp[0][0] << endl;
    
    return 0;
}