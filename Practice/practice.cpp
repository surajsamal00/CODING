// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

typedef long long ll;
int mod = 1000000007;


class Solution {
public:
    int N;
    vector<vector<int>> dp;
    vector<long long> val;

    int solve(int i, int x, long long target){
        if(target==0){
            return 1;
        }
        if(i>N || target<0){
            return 0;
        }

        if(dp[i][target]!= -1){
            return dp[i][target];
        }

        return dp[i][target] = ( solve(i+1, x, target - val[i]) 
                + solve(i+1, x, target) ) % mod;
    }
    int numberOfWays(int n, int x) {
        N = n;
        dp.assign(n+1, vector<int>(n+1,-1));
        val.assign(n+1,1);
        for(int i=1; i<=n; i++){
            val[i] = pow(i,x);
        }
        return solve(1, x, n);;

    }
};
int main(){
    int n = 2999;
    int x = 2;

    Solution obj = Solution();
    cout << obj.numberOfWays(n,x);
}

// clang++ -g main.cpp -o main