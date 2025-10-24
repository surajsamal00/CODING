#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
char mv[4] = {'R', 'D','L','U'};

template<typename T>
void print(T& v){
    for(auto x : v){
        
        cout <<  x << "";

    }
    cout << endl;
}



int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<char>> path(n, vector<char>(m,'X'));
    queue<tuple<int,int, char>> q;

    for(int i = 0; i < n; i++) {
        cin >> grid[i];
        for(int j = 0; j < m; j++) {
            if(grid[i][j] =='M'){
                q.push(make_tuple(i, j, grid[i][j]));
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] =='A'){
                q.push(make_tuple(i, j, grid[i][j]));
                path[i][j] = 'A';
            }
        }
    }

    int e_x = -1, e_y = -1;
    while(!q.empty()){
        auto [i, j, c] = q.front();
        q.pop();
        if(c == 'A'){
            if(i ==0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1){
                e_x  = i; e_y = j;
                break;
            }
        }
        for(int k = 0; k < 4; k++){
            int ni = i + dir[k][0], nj = j + dir[k][1];

            if(ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] == '.'){
                grid[ni][nj] = c;
                if(c == 'A'){
                    path[ni][nj] = mv[k];
                }
                q.push(make_tuple(ni, nj, c));
            }
        }
    }
    if(e_x == -1){
        cout << "NO";
    }
    else{
        vector<char> res;
        while(path[e_x][e_y]!='A'){
            res.push_back(path[e_x][e_y]);
            if(*res.rbegin() == 'L'){
                e_y++;
            }
            else if(*res.rbegin() == 'R'){
                e_y--;
            }
            else if(*res.rbegin() == 'U'){
                e_x++;
            }
            else if(*res.rbegin() == 'D'){
                e_x--;
            }
        }
        cout << "YES" << endl;
        reverse(res.begin(), res.end());
        cout << res.size() << endl;
        print(res);
    }

    
    return 0;
}
