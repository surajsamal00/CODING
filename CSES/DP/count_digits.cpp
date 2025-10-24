#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
 
int dp[20][11][2][2];
int solve(int i, int prev, bool trail, bool tight, string& s){
    if(i==s.size()){
        return 1;
    }
    if(dp[i][prev+1][trail][tight] != -1){
        return dp[i][prev+1][trail][tight];
    }
    int lb = 0;
    int ub = tight ? (s[i]-'0') : 9;
    int ans = 0;
    for(int dig = lb; dig <= ub; dig++){
        if(dig == 0){
            if(dig == prev && !trail) continue;
            ans += solve(i+1, dig, trail, tight && (dig == ub), s);
        }
        else{
            if(dig == prev) continue;
            ans += solve(i+1, dig, 0, tight && (dig == ub), s);
        }
    }
    return dp[i][prev+1][trail][tight] = ans;;
}
 
signed main() {
    int x, y;
    cin >> x >> y;
    if(x > y) swap(x, y);
    x--;
    string a = to_string(x);
    string b = to_string(y);
    while(a.size()<b.size()){
        a.insert(a.begin(),'0');
    }
    memset(dp, -1, sizeof(dp));
    int left = 0;
    if(x>=0) left = solve(0, -1, 1, 1, a);
    memset(dp, -1, sizeof(dp));
    int right = solve(0, -1, 1, 1, b);
    cout << right - left << endl;
    return 0;
}