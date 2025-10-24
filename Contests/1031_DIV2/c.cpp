#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
#define MOD 1000000007



void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void fileIO(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("output.txt","w", stdout);
    #endif
}


//--------------------Workspace--------------------//
template<typename T>
void print(T a) { //vector only
    for (auto x:a){
        cout << x << " ";
        // cout << setw(11) <<x ;
    }
    cout << endl;
}

template<typename T>
void print2D(T a){
    for(auto x:a){
        for(auto y:x){
            cout << y << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

void test(){
    int n,m,k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n,vector<int>(m,0));
    vector<vector<int>> prefix(n,vector<int>(m,0));
    int gold = 0;


    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            if(s[j]=='g'){
                grid[i][j] = 1;
                prefix[i][j] = 1;
                gold++;
            }
            if(s[j]=='#') grid[i][j] = 2;
        }
    }
    int mini = 1e12;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x=0,y=0,d=0;
            if(i-1>=0) y = prefix[i-1][j];
            if(j-1>=0) x = prefix[i][j-1];
            if(i-1>=0 && j-1>=0) d = prefix[i-1][j-1];

            prefix[i][j] += x + y - d; 

        }
    }

    // print2D(grid);
    // print2D(prefix);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==0){
                int tlx = max(0LL,i-k+1), tly = max(0LL,j-k+1);
                int brx = min(n-1,i+k-1), bry = min(m-1,j+k-1);
                int p=0,q=0,r=0,s=0;

                if(tlx-1>=0 && tly-1>=0) p = prefix[tlx-1][tly-1];
                if(tly-1>=0) r = prefix[brx][tly-1];
                if(tlx-1>=0) q = prefix[tlx-1][bry];

                s = prefix[brx][bry];

                int curr = s - q - r + p;
                mini = min(curr,mini);
            }

        }
    }
    cout << gold-mini << endl;
}

signed main() {
    

    fastIO();
    fileIO();
    // Start timer
    auto start = chrono::high_resolution_clock::now();
    
    int tc = 1;
    cin >> tc;  //comment this if not needed
    while (tc--) {
        test();
    }

    // End timer
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    #ifndef ONLINE_JUDGE
        cerr << "Runtime: " << duration.count() << " ms\n";
    #endif
    return 0;
}


/* //Revision

using ll = long long;

const int MAXN = 500;
int sum[MAXN + 1][MAXN + 1];

int n, m, k;
int check(int i, int mx) {
	return min(max(i, 0), mx);
}

int pref(int i, int j) {
	return sum[check(i, n)][check(j, m)];
}

void solve() {
	cin >> n >> m >> k; k--;
	vector<string> mine(n);
	int all_gold = 0;
	for (int i = 0; i < n; i++) {
		cin >> mine[i];
		for (int j = 0; j < m; j++) {
			all_gold += (mine[i][j] == 'g');
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + (mine[i][j] == 'g');
		}
	}
	int ans = all_gold;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mine[i][j] == '.') {
				int a = i - k, b = i + k + 1, c = j - k, d = j + k + 1;
				ans = min(ans, pref(b, d) - pref(a, d) - pref(b, c) + pref(a, c));
			}
		}
	}
	cout << all_gold - ans << "\n";
}

*/