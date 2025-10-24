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
	int n, m, N;
	cin >> n >> m;
	N=n;
	if(m<n || m>((n)*(n+1))/2){
		cout << -1 << endl;
		return;
	}
	if(n==1){
		cout << 1 << endl;
		return;
	}
	set<int> mp;
	for(int i=1;i<=N;i++){
		mp.insert(i);
	}
	int prev = 0;
	while(mp.size()!=m){
		int a = m - mp.size() + 1;
		int curr = min(*mp.rbegin(),a);
		mp.erase(curr);
		if(prev==0){
			cout << curr << endl;
		}
		else{
			cout << prev << " " << curr << "\n";
		}
		m-=curr;
		prev = curr;
	}
	if(!mp.empty()){
		if(mp.size()==N){
			cout << 1 << "\n";
		}
		else{
			cout << prev << " " << 1 << "\n";
		}
		mp.erase(1);
		while(!mp.empty()){
			cout << 1 << " " << *mp.begin() << "\n";
			mp.erase(mp.begin());
		}
	}

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