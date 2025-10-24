#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;


int main() {
    int t, n;
    vector<long long> dpx(1e6+1,0);
    vector<long long> dpy(1e6+1,0);
    dpx[1] = 1;
    dpy[1] = 1;
    for(int i=2; i <=1e6; i++){
        dpx[i] += (dpx[i-1] + dpy[i-1]);
        dpy[i] += (dpx[i-1] + dpy[i-1]);

        dpx[i] += (3*dpx[i-1])%mod;
        dpy[i] += (dpy[i-1]);
        
        dpx[i] %= mod;
        dpy[i] %= mod;

    }
    cin >> t;
    while(t--) {
        cin >> n;
        cout << (dpx[n] + dpy[n]) % mod << endl;
    }

    
    return 0;
}
