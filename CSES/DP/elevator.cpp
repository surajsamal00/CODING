#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int,int>> dp;

pair<int, int> solve(int mask, int& limit, vector<int>& wt){
    if(mask == 0){
        return make_pair(1, 0);
    }
    if(dp[mask].first != -1) {
        return dp[mask];
    }
    int rides = INT_MAX;  //first priority
    int occupied = INT_MAX; //second priority
    for(int i = 0; i<20; i++){
        if(mask & (1<<i)){
            //  consider this as to be the last person to board the lift in current mask;
            //  what would the optimal state of events just before this guy (mask doesn't contain this guy)

            auto [curr_r, curr_o] = solve(mask & ~(1<<i), limit, wt);
            if(limit - curr_o >= wt[i]){
                // seat this guy in the same ride and update curr occupied
                curr_o += wt[i];
            }
            else{
                // send the lift and start a new fresh ride
                curr_r += 1;
                curr_o = wt[i];
            }

            //check with the optimum
            if(curr_r < rides){
                rides = curr_r;
                occupied = curr_o;
            }
            else if(curr_r == rides && curr_o < occupied){
                occupied = curr_o;
            }
        }
    }

    return dp[mask] = make_pair(rides, occupied);
}
signed main() {
    
    int n, x;
    cin >> n >> x;
    vector<int> wt(n);
    for(int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    int mask = (1<<n) - 1;
    dp.assign(mask+1,make_pair(-1,-1));

    auto [rides, occupied] = solve(mask, x, wt);
    cout << rides << endl;

    return 0;
}
