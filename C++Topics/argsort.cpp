#include <bits/stdc++.h>
using namespace std;

template<typename T>
void print(T a){
    for(auto x : a){
        cout << setw(4) << x;
    }
    cout << endl;
}
int main(){

    vector<int> arr{42, 7, 19, 88, 3, 56, 24};
    vector<int> idx(arr.size());
    iota(idx.begin(), idx.end(), 0);

    print(arr);
    print(idx);
    cout << endl;


    auto comp = [&](int i, int j){
        return arr[i] < arr[j];
    };
    sort(idx.begin(), idx.end(), comp);
    
    
    

    for(int i=0; i<idx.size(); i++){
        cout << setw(4) << arr[idx[i]];
    }
    cout << endl;
    print(idx);


    return 0;
}

    