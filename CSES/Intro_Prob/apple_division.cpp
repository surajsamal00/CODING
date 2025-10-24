#include<bits/stdc++.h>
using namespace std;
#define int long long

int diff(int mask, int total, vector<int>& apples){
    int curr = 0;
    for(int i = 0; i < apples.size(); i++){
        if(mask&(1<<i)){
            curr += apples[i];
        }
    }
    return abs(total - 2*curr);
}

signed main(){
    int n;
    cin >> n;
    int ans = LLONG_MAX;
    int full_mask = (1<<(n+1)) - 1;
    vector<int> a(n);
    int total = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
    }

    for(int mask = 0; mask <= full_mask; mask++){
        ans = min(ans, diff(mask,total, a));
    }
    cout << ans << endl;

    return 0;
}