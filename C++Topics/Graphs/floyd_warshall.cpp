#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // n = 100 so floyd warshall is MultiSource Shortest Path is allowed

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // 1. Set the diagonals as zero distance
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // 2. Set the existing edges as given weights distance (rest are currently unreachable/infinity) 
        for (auto e : edges) {
            dist[e[0]][e[1]] = dist[e[1]][e[0]] = e[2];
        }

        // 3. Start with zero as middle via node;
        //    start->end and start->middle + middle->end;

        for (int via = 0; via < n; via++) {
            for (int start = 0; start < n; start++) {
                for (int end = 0; end < n; end++) {
                    if(dist[start][via] == INT_MAX || dist[via][end] == INT_MAX) continue;
                    dist[start][end] = min(dist[start][end], dist[start][via] + dist[via][end]);
                }
            }
        }

        int city = 0;
        int cnt = INT_MAX;

        for(int i = 0; i < n; i++) {
            int curr = 0;
            for(int j = 0; j < n; j++) {
                if(dist[i][j] <= distanceThreshold){
                    curr++;
                }
            }
            if(curr<cnt){
                cnt = curr;
                city = i;
            }
            else if(curr == cnt) {
                city = max(i,city);
            }
        }

        return city;
    }
};

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
}