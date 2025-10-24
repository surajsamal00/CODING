#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
#define MOD 1000000007

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void fileIO(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w", stdout);
    #endif
}

//----------Utilities-------//


struct CustomHash {  //use map first if nlogn is allowed no need to use this..
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(int x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64((uint64_t)x + FIXED_RANDOM);
    }
};


template<typename T>
void print(T a) { 
    for (auto x:a){
        cout << x << " ";
        // cout << setw(20) << x ;
    }
    cout << endl;
}

template<typename T>
void print2D(T a){
    for(auto x:a){
        for(auto y:x){
            // cout << y << " ";
            cout << setw(20) << y ;
        }
        cout << endl;
    }
    cout << endl;
}



vector<int> prime;
void prime_generator(){
    prime.assign(1000007,true);
    prime[0] = false;
    prime[1] = false;
    for(int i=2; i*i<prime.size(); i++){
        if(prime[i]){
            for(int j=i*i; j<prime.size(); j+=i){
                prime[j] = false;
            }
        }
    }
}



long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long LCM(long long a, long long b){
    return (a*b)/gcd(a,b);
}

int clipper(int val, int lo, int hi){
    return min(max(val,lo),hi);
}

bool is_palindrome(vector<int> &a){
    int n = a.size();
    for(int i=0; i<n/2;i++){
        if(a[i]!=a[n-1-i]) return false;
    }
    return true;
}

long long power(long long a, int b) {
    long long res = 1;
    while(b){
        if(b & 1) res = res * a;
        a = a * a ;
        b >>= 1;
    }
    return res;
}

int mod_pow(int a, int b, int p) {
    int res = 1;
    a %= p;
    while(b){
        if(b & 1) res = 1LL * res * a % p;
        a = 1LL * a * a % p;
        b >>= 1;
    }
    return res;
}




//--------------------------//


void test(){
    

}

signed main() {

    // Start timer
    auto start = chrono::high_resolution_clock::now();

    //cout << "debug" << endl;
    fileIO();
    fastIO();


    vector<int> a{1,12,22222222,4};
    vector<vector<int>> b{{1,12,22222222,4},{99999999 , 0, 12,883733829}};
    print(a);
    print2D(b);
    int tc = 1;
    cin >> tc;  //comment this if not needed

    while (tc--) {
        test();
    }

    // End timer
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    #ifndef ONLINE_JUDGE
        cerr << "Runtime: " << duration.count() << " ms\n";
    #endif

    return 0;
}


