#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int dir[4][2] = {{0,1}, {1,0}, {0, -1}, {-1, 0}}; 

template<typename T>
void print(T a) { 
    for (auto x:a){
        // cout << x << " ";
        // // cout << setw(20) << x ;
        for(auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(int i, int j, int n, int m, vector<string>& a){
    a[i][j] = '#';
    for(int k = 0; k < 4; k++) {
        int ni = i + dir[k][0], nj = j + dir[k][1];
        if(ni >= 0 && nj >= 0 && ni < n && nj < m && a[ni][nj] != '#'){
            dfs(ni, nj, n, m, a);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != '#') {
                cnt += 1;
                dfs(i, j, n, m, a);
            }
        }
    }
    cout << cnt;
    return 0;
}