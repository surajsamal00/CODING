#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> run_lis;
    for(int i = 0; i < n; i++){
        int x = a[i];
        auto it = lower_bound(run_lis.begin(), run_lis.end(), x);
        if(it == run_lis.end()){
            run_lis.push_back(x);
        }
        else{
            *it = x;
        }
    }
    int ans = run_lis.size();
    cout << ans;
    return 0;
}
