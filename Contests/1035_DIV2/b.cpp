#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
#define MOD 1000000007

template<typename T>
void print(T a) { //vector only
    for (auto x:a){
        cout << x << " ";
        // cout << setw(20) << x ;
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        double px,py,qx,qy;
        cin >> px >> py >> qx >> qy;
        vector<double> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        double val= 0;
        val +=  ((px-qx)*(px-qx)) + ((py-qy)*(py-qy));
        // cout << val  << endl;
        val = sqrt(val);
        a.push_back(val);
        sort(a.rbegin(),a.rend());
        double sum = 0;
        // print(a);
        for(int i=1; i<=n; i++){
            sum += a[i];
        }

        (sum>=a[0])? cout<< "YES\n": cout << "NO\n";
    }
    return 0;
}