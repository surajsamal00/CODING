#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> fen;
    int N;

public:
    FenwickTree(int n) {
        N = n + 2; // handle 1-based index safely
        fen.assign(N, 0);
    }

    void update(int i, int val) {
        while (i < N) {
            fen[i] += val;
            i += (i & -i);
        }
    }

    int sum(int i) {
        int res = 0;
        while (i > 0) {
            res += fen[i];
            i -= (i & -i);
        }
        return res;
    }

    int range_sum(int l, int r) {
        if (l > r) swap(l, r);
        return sum(r) - sum(l - 1);
    }
};


int main() {
    vector<int> a{2, 4, 5, 2, 1, 23, 56, 82};
    FenwickTree ft(a.size());

    for (int i = 0; i < a.size(); i++) {
        ft.update(i + 1, a[i]); // 1-based
    }

    cout << ft.range_sum(5, 5) << endl;
}
