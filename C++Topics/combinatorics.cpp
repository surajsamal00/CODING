#include <bits/stdc++.h>
using namespace std;
/*
use lucas theorem if mod val is less than n/r of nCr.
or directly use the fermat theorem for each inv_mod instead of multiplication.
*/

constexpr int N = 1e6 + 5;
constexpr int mod = 1e9 + 7;
long long fact[N], invfact[N]; //  {(a!)/(b!)} mod p => [ {(a!) mod p} * {mod inverse of b!} ]whole mod p 

//fast exponentiation
long long modpow(long long a, long long b, long long m=mod){
    long long res = 1;
    while(b>0){
        if(b&1){
            res = (res*a) % m;
        }
        a = (a*a) % m;
        b = b>>1;
    }
    return res;
}

void precompute(){
    fact[0] = invfact[0] = 1;
    for(int i=1; i<N; i++) {
        fact[i] = (fact[i-1]*i)%mod;
    }

    invfact[N-1] = modpow(fact[N-1], mod - 2, mod); // fermats little theorem

    for(int i= N - 2; i>0; i--) {
        invfact[i] = invfact[i+1]*(i+1) % mod;
    }
}

long long nCr(int n, int r){
    return ( ((fact[n] * invfact[r]) % mod ) * invfact[n-r]) % mod;
}


int main(){
    precompute();
    for(int n = 0; n<10; n++){
        for(int i=0; i<=n; i++){
            cout << nCr(n, i) << " ";
        }
        cout << endl;
    }
}