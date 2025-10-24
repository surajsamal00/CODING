#include <bits/stdc++.h>
using namespace std;
#define int long long

/* Variables */
int mod = 676767677; 

template<typename T>
void print(T a) { 
    for (auto x : a) {
        cout << x << " ";
    }
    cout << endl;
}


void test_case() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    set<int> s, all;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
        all.insert(i+1);
    }
    if(s.size() == n) {
        for(int i = 0; i < k; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    for(auto itr : s) {
        all.erase(itr);
    }
    int first = *all.begin();
    int second = -1;
    set<int>().swap(all);
    for(int i = 1; i <= n; i++) {
        if(i != first && i != arr[n-1] && second == -1) {
            second = i;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(i != first && i != second) {
            all.insert(i);
        }
    }
    if(arr.size() < n + k) {
        arr.push_back(first);
    }
    if(arr.size() < n + k) {
        arr.push_back(second);
    }
    while(arr.size() < n + k) {
        arr.push_back(*all.begin());
        all.erase(all.begin());
    }
    for(int i = n; i < n + k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    while(T--) {
        test_case();
    }
    return 0;
}