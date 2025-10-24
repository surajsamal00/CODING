#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

void shift(int n, int top, int left, int right, int middle){
    if(n == 1){
        cout <<"MOVE Disc " << top << " :: From Tower " << left << "->" << right << endl;
    }
    else{
        shift(n-1, top, left, middle, right);
        cout <<"MOVE Disc " << n << " :: From Tower " << left << "->" << right << endl;
        shift(n-1, top, middle, right, left);
    }
}

int main() {
    int n;
    cin >> n;
    int discs = 0;
    unsigned long long curr = 0;
    for(int i = 1; i <=n; i++){
        curr = curr*2 + 1;
        // cout << curr << endl;
    }
    cout << curr << endl;
    // shift(n, 1, 1, 3, 2);
    return 0;
}