#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int main(){
    int t, a, b;
    cin >> t;
    while(t-- > 0){
        cin >> a >> b;
        vector<int> num1,num2;
        while(a>0){
            num1.push_back(a%10); //filled in reverse manner 1934 -> [4,3,9,1]
            num2.push_back(b%10);
            
            a/=10;
            b/=10;
        }
        reverse(num1.begin(), num1.end()); //correct order
        reverse(num2.begin(), num2.end());
        vector<int> x(num1.size(),0);

        int ans = 0;
        int prefix1 = 0;
        int prefix2 = 0;
        for(int i=0;i<num1.size();i++){
            prefix1 = prefix1*10 + num1[i];
            prefix2 = prefix2*10 + num2[i];
            if(prefix1+1<prefix2){
                break;
            }
            else if(prefix1+1 == prefix2){
                ans += 1;
            }
            else{
                ans += 2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}