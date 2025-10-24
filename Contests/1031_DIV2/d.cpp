#include<iostream>
using namespace std;

int clipper(int val, int lo, int hi){
    return min(max(val,lo),hi);
}
int main(){
    int t = 6;
    int val;
    while(t--){
        cin >> val;
        cout << clipper(val,-2,8) << "\n\n";
    }    
    return 0;
}