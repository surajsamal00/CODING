#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;


int main() {
    int n;
    cin >> n;
    bitset<1000007> dp(1);
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 0; i<n; i++){
        dp |= (dp<<a[i]);
    }
    cout << dp.count() - 1 << endl; // zero is excluded.
    for(int i = 1; i<=dp.size(); i++){
        if(dp[i]){
            cout << i << " ";
        }
    }
    return 0;
}
