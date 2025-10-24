#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;
#define int long long

/* Variables */
int mod = 998244353; 

template<typename T>
void print(T a) { 
    for (auto x:a){
        cout << x << " ";
    }
    cout << endl;
}


void solve(int tc, int n, int q, vector<int>& a, vector<array<int, 2>> & query, vector<vector<int>>& res) {
    vector<int> pre_z(n+1,0), pre_o(n+1,0);
    for(int i = 1; i <= n; i++) {
        if(a[i]==0){
            pre_z[i] = 1;
        }
        else{
            pre_o[i] = 1;
        }
        pre_z[i] += pre_z[i-1];
        pre_o[i] += pre_o[i-1];
    }
    vector<int> same(n+2, 0);
    for(int i = 2; i <= n; i++) {
        same[i] += same[i-1];
        if(a[i] == a[i-1]) {
            same[i] += 1;
        }
    }
    int l, r;
    vector<int> ans;
    for(int i = 0; i < q; i++) {
        l = query[i][0], r = query[i][1];
        if((pre_z[r] - pre_z[l-1])%3 != 0 || (pre_o[r] - pre_o[l-1])%3 != 0) {
            // cout << -1 << endl;
            ans.push_back(-1);
            continue;
        }
        int extra = 0;
        if(same[r] == same[l-1]) extra = 1;
        else if(same[r] == (same[l-1] + 1) && a[l]==a[l-1]) extra++;
        ans.push_back((pre_z[r] - pre_z[l-1])/3 + (pre_o[r] - pre_o[l-1])/3 + extra);
    }
    res[tc] = ans;
}

class ThreadPool {
    vector<thread> workers;
    queue<function<void()>> tasks;
    mutex mtx;
    condition_variable cv;
    bool stop = false;

public:
    ThreadPool(size_t threads = thread::hardware_concurrency()) {
        for (size_t i = 0; i < threads; i++) {
            workers.emplace_back([this] {
                while (true) {
                    function<void()> task;
                    {
                        unique_lock<mutex> lock(mtx);
                        cv.wait(lock, [this] { return stop || !tasks.empty(); });
                        if (stop && tasks.empty()) return;
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
            });
        }
    }

    template<class F, class... Args>
    void enqueue(F&& f, Args&&... args) {
        {
            unique_lock<mutex> lock(mtx);
            tasks.emplace(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        }
        cv.notify_one();
    }

    ~ThreadPool() {
        {
            unique_lock<mutex> lock(mtx);
            stop = true;
        }
        cv.notify_all();
        for (thread &t : workers)
            t.join();
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto start = chrono::high_resolution_clock::now();

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T = 1, n , q;
    cin >> T;
    vector<vector<int>> arr;
    vector<vector<array<int,2>>> queries;
    vector<vector<int>> params;

    vector<vector<int>> res(T);

    for(int t = 0; t < T; t++){
        cin >> n >> q;
        vector<int> a(n+1,0);
        a[0] = -1;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<array<int,2>> query;
        int l, r;
        for(int i = 0; i < q; i++) {
            cin >> l >> r;
            query.push_back({l, r});
        }
        arr.push_back(a);
        queries.push_back(query);
        params.push_back({n, q});

    }

    // vector<thread> threads;
    // for (int i = 0; i < T; i++) {
    //     threads.emplace_back(solve, i, params[i][0], params[i][1], ref(arr[i]), ref(queries[i]), ref(res));
    // }

    {
        ThreadPool pool(8);
        for (int i = 0; i < T; i++) {
            pool.enqueue(solve, i, params[i][0], params[i][1], ref(arr[i]), ref(queries[i]), ref(res));
        }
    } //<- scoping calls destructor;

    for(auto &v : res) {
        for(auto &x : v) {
            cout << x << "\n";
        }
    }
    // End timer
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    #ifndef ONLINE_JUDGE
        cerr << "Runtime: " << duration.count() << " ms\n";
    #endif
    return 0;
}