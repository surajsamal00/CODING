#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int dir[4][2] = {{0,1}, {1,0}, {0, -1}, {-1, 0}}; 
char pth[4] = {'R', 'D', 'L', 'U'};

template<typename T>
void print(T a) { 
    for (auto x:a){
        cout << x << "";
        // cout << setw(20) << x ;
        // for(auto y : x){
        //     cout << y << " ";
        // }
        // cout << endl;
    }
    cout << endl;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int sx = 0, sy = 0, ex = 0, ey = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'A'){
                sx = i; sy = j;
            }
            if(a[i][j] == 'B'){
                ex = i; ey = j;
            }
        }
    }
    
    queue<tuple<int,int>> q;
    vector<vector<char>> path(n, vector<char>(m,'X'));
    a[sx][sy] = '#';
    q.push(make_tuple(sx, sy));

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int ni = i + dir[k][0], nj = j + dir[k][1];
            if(ni >= 0 && nj >= 0 && ni < n && nj < m && a[ni][nj] != '#'){
                path[ni][nj] = pth[k];
                if(a[ni][nj] == 'B'){
                    q = queue<tuple<int,int>>();
                    break;
                }
                else{
                    a[ni][nj] = '#';
                    q.push(make_tuple(ni, nj));
                }

            }
        }

    }

    string res = "";
    while(path[ex][ey] != 'X'){
        res += path[ex][ey];
        if(path[ex][ey] == 'L'){
            ey++;
        }
        else if(path[ex][ey] == 'R'){
            ey--;
        }
        else if(path[ex][ey] == 'D'){
            ex--;
        }
        else if(path[ex][ey] == 'U'){
            ex++;
        }
    }

    reverse(res.begin(), res.end());
    if(res.size()==0){
        cout << "NO\n";
    }
    else{
        cout << "YES\n" << res.size() << endl << res << endl;
    }
    
    
    return 0;
}