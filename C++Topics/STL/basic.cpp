#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Comp2{
    int k;
    Comp2(int n) : k(n) {}
    bool operator()(const int x, const int y) const {
        return (x%k) < (y%k);
    }
};

struct comp {
    bool reverse;
    comp(bool rev) : reverse(rev) {}
    bool operator()(int a, int b) const {
        return reverse ? a < b : a > b;
    }
};

// Now you must pass an object:
priority_queue<int, vector<int>, comp> pq1(comp(true));  // min-heap
priority_queue<int, vector<int>, comp> pq2(comp(false)); // max-heap


int main(){
    int val = 5;



    
    // Safe Erase multiset:
    // never use ms.erase(val) it will erase all instances;
    // also don't create multiple itr if erase is involved (it makes prev valid itrs' as invalid..)
    multiset<int> ms;
    if(auto it = ms.find(val); it != ms.end()){
        ms.erase(it);
    }



    // if you want a min/max heap with the ability to pop from random node
    // where the heap contains values from unique keys(ex- mode, ultimate_parent's size etc)
    // use multiset + map
    // multiset to store values and get pq.top() and map to manupulate key-value in the nodes in heap
    map<int, int> mp2;
    multiset<int> ms2;
    // insert value of key 
    ms.insert(val);

    // for any kind of update
    // remove from both map and multiset do the updates and push back in both



   
    /*
    //Comparator(stateless)
    struct Comp{
        bool operator()(const int x, const int y) const{
            return x < y;
        }
    };
    priority_queue<int, vector<int>, Comp> pq;

    //Compartor(stateful)
    struct Comp{
        int k;
        Comp(int n) : k(n) {}
        bool operator()(const int x, const int y) const{
            return (x%k) < (y%k);
        }
    };
    priority_queue<int, vector<int>, Comp> pq{Comp(k)};

    */



    class Point {
    public:
        int x, y;

        Point(int x, int y) : x(x), y(y) {}

        // Define how to compare two Points
        bool operator<(const Point& other) const {
            // Example: sort by x, then by y
            if (x == other.x)
                return y < other.y;
            return x < other.x;
        }
    };
    vector<Point> v = { {2,3}, {1,5}, {2,1} };
    sort(v.begin(), v.end()); //sort calls x < y and due to compile time operator overloading 
                              // polymorphism it gets properly sorted.

    return 0;
}