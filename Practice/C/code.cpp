#include <iostream>
using namespace std;
int main(){
    // int question = 0x68617264;
    int question = 'hard';
    cout << question << endl; // weird conversion
    /*
    'h' = 0x68
    'a' = 0x61
    'r' = 0x72
    'd' = 0x64
    q = 0x68617264 = 1751216740 (decimal)
    */
    if(question == 'hard') {
        // if(question == 'hard') break; //<-- break can't be used without loop
        cout << "not that hard";
    }
    cout << "its easy\n";

    int arr[5] = {11,22,33,44,55};
    for(int i = 0; i < 5; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    char name[5] = "Math"; // name[4] is error because one byte is required for \0.
    cout << name;

}

template <class T> class node { public: node* next; T value; };