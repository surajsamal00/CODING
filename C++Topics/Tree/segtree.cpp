#include <bits/stdc++.h>
using namespace std;

struct segtree {
    int N;
    vector<int> tree, lazy;
    vector<bool> isLazy;

    segtree(int n) {
        N = n;
        tree.assign(4*N, 0);
        lazy.assign(4*N, INT_MIN);
        isLazy.assign(4*N, false);
    }

    void build(int node, int start, int end, vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2*node + 1, start, mid, arr);
        build(2*node + 2, mid + 1, end, arr);
        tree[node] = max(tree[2*node + 1], tree[2*node + 2]);
    }

    void push(int node, int start, int end) {
        if (!isLazy[node]) return;
        tree[node] = max(tree[node], lazy[node]);
        if (start != end) {
            int left = 2*node + 1, right = 2*node + 2;
            lazy[left] = max(lazy[left], lazy[node]);
            lazy[right] = max(lazy[right], lazy[node]);
            isLazy[left] = isLazy[right] = true;
        }
        lazy[node] = INT_MIN;
        isLazy[node] = false;
    }

    void update(int node, int start, int end, int ql, int qr, int val) {
        push(node, start, end);
        if (start > qr || end < ql) return;
        if (start >= ql && end <= qr) {
            lazy[node] = val; //already pushed in begining of update so this is not lazy right now;
            isLazy[node] = true;
            push(node, start, end);
            return;
        }
        
        int mid = (start + end) / 2;
        update(2*node + 1, start, mid, ql, qr, val);
        update(2*node + 2, mid + 1, end, ql, qr, val);
        tree[node] = max(tree[2*node + 1], tree[2*node + 2]);
    }

    int query(int node, int start, int end, int ql, int qr) {
        push(node, start, end);
        if (start > qr || end < ql) return INT_MIN;
        if (start >= ql && end <= qr) return tree[node];
        int mid = (start + end) / 2;
        return max(query(2*node + 1, start, mid, ql, qr),
                   query(2*node + 2, mid + 1, end, ql, qr));
    }
};

int main() {
    vector<int> a{1,4,2,34,6,45,2,12,0,-1,4,12,-92,11};
    int n = a.size();
    segtree seg(n);
    seg.build(0,0,n-1,a);

    cout << "Initial query(8,9): " << seg.query(0,0,n-1,8,9) << "\n";

    seg.update(0,0,n-1,7,11,20); // increase range to at least 20
    cout << "After update(7,11,20): " << seg.query(0,0,n-1,8,9) << "\n";
}
