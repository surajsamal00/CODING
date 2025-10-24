#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;


int process(vector<int>& a){
    int mx = 1;
    int curr = 1;
    int prev = a[0];
    for(int i = 1; i < a.size(); i++){
        if(a[i] >= prev){
            mx = max(mx, curr);
            curr = 1;
            prev = a[i];
        }
        else{
            curr++;
        }
    }
    mx = max(mx, curr);
    return mx;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mx = process(a);
    reverse(a.begin(), a.end());
    mx = max(mx, process(a));
    cout << mx;
    return 0;
}
