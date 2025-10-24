#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
#define MOD 1000000007

void fileIO();

template<typename T>
void print2D(T a){
    for(auto x:a){
        for(auto y:x){
            cout << y << " ";
            // cout << setw(20) << y ;
        }
        cout << endl;
    }
    cout << endl;
}

void test(){
	int n,s;
	cin >> n >> s;
	int ans = 0;
	int dx,dy,x,y;
	for(int i=0; i<n; i++){
		cin >> dx >> dy >> x >> y;

		if((dx==1 && dy==1)|| (dx==-1 && dy==-1)){
			ans += (y==x);
		}
		else{
			ans += (x+y==s);
		}
	}
	cout << ans << endl;
}

signed main() {
    fileIO();
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    test();
	}
	return 0;
}

void fileIO(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w", stdout);
    #endif
}