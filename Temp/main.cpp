#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        int req = sum - x;
        ans += mp[req];
        mp[sum]++;
    }
    cout << ans << endl;
    return 0;
}