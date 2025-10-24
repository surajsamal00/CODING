#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

void adder(vector<string>& s){
    vector<string> res;
    char w = '0';
    for(int i = 0; i < s.size(); i++){
        string str = s[i];
        str.insert(str.begin(), w);
        res.push_back(str);
    }
    w = '1';
    for(int i = s.size()-1; i >= 0; i--){
        string str = s[i];
        str.insert(str.begin(), w);
        res.push_back(str);
    }
    swap(res, s);
    
}

template<typename T>
void print(T a){
    for(auto x : a){
        cout << x << endl;
    }
}
int main() {
    int n;
    cin >> n;
    vector<string> s{"0","1"};
    while(n>1){
        n--;
        adder(s);
    }
    print(s);
    return 0;
}
