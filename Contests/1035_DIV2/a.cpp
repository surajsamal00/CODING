#include <bits/stdc++.h>
using namespace std;
void fileIO(); 

typedef long long ll;
#define MOD 1000000007

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(int l1, int b1, int l2, int b2, int l3, int b3){
	if(l3+l2==l1 && b3==b2 && b3+b1==l1) return true;
	if(l1==l2 && l2==l3 && (b1+b2+b3)==l1) return true;
	else return false;
}

void test(){
	int l1,b1,l2,b2,l3,b3;
	cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

	if(check(l1,b1,l2,b2,l3,b3) || check(b1,l1,b2,l2,b3,l3)){
		cout << "YES\n";
	}

	else{
		cout << "NO\n";
	}

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
