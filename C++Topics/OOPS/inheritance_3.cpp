#include <iostream>
using namespace std;

// If you define yourself the constructor you must call all required base class constructors
// explicitly.
class Base1 {
public:
    Base1(int x) { std::cout << "Base1: " << x << "\n"; }
};

class Base2 {
public:
    Base2(int y) { std::cout << "Base2: " << y << "\n"; }
};

class Derived : public Base1, public Base2 {
public:
    Derived(int a, int b, int c)
        : Base1(a), Base2(b) // call base constructors explicitly
    {
        std::cout << "Derived: " << c << "\n";
    }
};
