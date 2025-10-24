#include <bits/stdc++.h>
using namespace std;

// RANGE SUM (1-based):
struct SegTree {
    vector<long long> seg, lazy;
    int N;

    SegTree(int n) {
        N = n;
        seg.assign(4 * N, 0);
        lazy.assign(4 * N, 0);
    }

    void build(int node, int l, int r, vector<int>& arr) {
        if (l == r) {
            seg[node] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(node * 2, l, mid, arr);
        build(node * 2 + 1, mid + 1, r, arr);
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }

    void push(int idx, int l, int r) {
        if (lazy[idx] != 0) {
            seg[idx] += (r - l + 1) * lazy[idx];

            //if not leaf node
            if (l != r) {
                lazy[idx * 2] += lazy[idx];
                lazy[idx * 2 + 1] += lazy[idx];
            }

            lazy[idx] = 0;
        }
    }

    void update(int idx, int l, int r, int ql, int qr, long long val) {
        push(idx, l, r);

        if (r < ql || l > qr) return;
        if (ql <= l && r <= qr) {
            lazy[idx] += val;
            push(idx, l, r);
            return;
        }

        int mid = l + (r - l) / 2;
        update(idx * 2, l, mid, ql, qr, val);
        update(idx * 2 + 1, mid + 1, r, ql, qr, val);
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }

    long long query(int idx, int l, int r, int ql, int qr) {
        push(idx, l, r);
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return seg[idx];
        int mid = l + (r - l) / 2;
        return query(idx * 2, l, mid, ql, qr) +
               query(idx * 2 + 1, mid + 1, r, ql, qr);
    }
};

int main() {
    int n = 8;
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    SegTree st(n+2);
    st.build(1, 1, n, arr);
    st.update(1, 1, n, 3, 5, 5);
    cout << st.query(1, 1, n, 1, 5) << "\n"; // expected: 1+2+(3+5)+(4+5)+(5+5) = 30
}
