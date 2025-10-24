#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007
void fileIO(); 

template<typename T>
void print(T a) { //vector only
    for (auto x:a){
        cout << x << " ";
        // cout << setw(6) << x ;
    }
    cout << endl;
}

void test(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    // print(a);
    int bob = *a.rbegin();
    // cout << bob << endl;
    ll cnt = 0;
    for(int i=0; i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            if(a[i]+a[j]>bob){
                cnt += n-j-1;
                break;
            }
            
        }
    }
    // cout << cnt << endl;
    for(int i=0; i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            // cout << j << ":"<< cnt << endl;
            int curr = a[i]+ a[j];
            int req = bob - curr + 1;
            
            // if(j==n-2) continue;
            int pos = lower_bound(a.begin()+j+1,a.begin()+n-1,req)-a.begin();
            int pos2 = lower_bound(a.begin()+j+1,a.begin()+n-1,curr)-a.begin();
            int a = 0, b = 0;
            if(pos>j && pos<n-1){
                a = n-pos-1;
            }
            if(pos2>j && pos2<n-1){
                b = n-pos2-1;
            }

            cnt += max(0,a-b);
            // cout << n-pos-1<<endl;
            
        }
    }
    cout << cnt << endl;

}

int main() {
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