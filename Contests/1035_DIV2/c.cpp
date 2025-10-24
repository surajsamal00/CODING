#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
#define MOD 1000000007

signed main(){
    int t;
    cin >> t;
    while(t--){
        long long n,l,r,k;
        cin >> n >> l >> r >> k;
        if(n&1){
            cout << l << endl;
            continue;
        }
        else if(n==2){
            cout << -1 << endl;
            continue;
        }
        long long left = l;
        int bits = 0;
        while(left>0){
            bits++;
            left>>=1;
        }
        long long num1 = 1LL<<bits;
        if(num1>r){
            cout << -1 << endl;
        }
        else if(k<n-1){
            cout << l << endl;
        }
        else{
            cout << num1 << endl;
        }
    }
    return 0;
}