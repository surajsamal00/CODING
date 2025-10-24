#include <iostream>
using namespace std;

class Character {
    // properties
    private: //also the default member type
    int health;
    bool male; // due to padding/greedy alignment health + male will take 8 bytes

    int level;

    

    public:
    string job;

    Character() {
        cout << "1st constructor called\n";
    }

    Character(string job) {  //function overloading (wrt parameters)
        cout << "2nd constructor called\n";
        this->job = job;
    }

    int getLevel(){
        return this->level;
    }

    void setLevel(int lvl){ //can access private members/functions.
        this->level = lvl;
    }

    protected:
};


int main() {
    Character suraj;

    // suraj.health = 9; //inaccessible private member

    //static allocation
    Character baibhav;
    baibhav.job = "MarutiSuzuki";

    //dynamic allocation
    Character* sourav = new Character("adobe");
    (*sourav).job = "Adobe";
    sourav->job = "daharami";
    
    


    cout << sizeof(suraj) << endl; // if no property still 1 byte takes in memory.
    return 0;
}