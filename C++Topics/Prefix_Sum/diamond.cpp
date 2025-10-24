#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
int N;
vector<vector<ll>> grid, left_diag, right_diag;

// Utility for boundary checking
bool check(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    cin >> N;
    grid.assign(N, vector<ll>(N));
    left_diag.assign(N, vector<ll>(N, 0));
    right_diag.assign(N, vector<ll>(N, 0));

    ll maxi = LLONG_MIN;

    // Input and initialize diagonals
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            maxi = max(maxi, grid[i][j]);
            left_diag[i][j] = grid[i][j];   // '\'
            right_diag[i][j] = grid[i][j];  // '/'
        }
    }

    // Build prefix sums for left diagonals '\'
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            left_diag[i][j] += left_diag[i - 1][j - 1];
        }
    }

    // Build prefix sums for right diagonals '/'
    for (int i = 1; i < N; i++) {
        for (int j = 0; j + 1 < N; j++) {
            right_diag[i][j] += right_diag[i - 1][j + 1];
        }
    }

    // Try all centers
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ll sum = grid[i][j];  // Radius 0
            maxi = max(maxi, sum);

            int max_r = min({i, j, N - 1 - i, N - 1 - j});

            for (int r = 1; r <= max_r; r++) {
                int topx = i - r, topy = j;
                int botx = i + r, boty = j;
                int leftx = i, lefty = j - r;
                int rightx = i, righty = j + r;

                ll layer_sum = sum;

                // '/' top to left
                if (check(leftx, lefty))
                    layer_sum += right_diag[leftx][lefty];
                if (check(topx - 1, topy + 1))
                    layer_sum -= right_diag[topx - 1][topy + 1];

                // '\' left to bottom
                if (check(botx, boty))
                    layer_sum += left_diag[botx][boty];
                if (check(leftx - 1, lefty - 1))
                    layer_sum -= left_diag[leftx - 1][lefty - 1];

                // '/' bottom to right
                if (check(botx, boty))
                    layer_sum += right_diag[botx][boty];
                if (check(rightx - 1, righty + 1))
                    layer_sum -= right_diag[rightx - 1][righty + 1];

                // '\' right to top
                if (check(i, righty))
                    layer_sum += left_diag[i][righty];
                if (check(topx - 1, topy - 1))
                    layer_sum -= left_diag[topx - 1][topy - 1];

                // Remove 4 corners (added twice)
                layer_sum -= grid[topx][topy];
                layer_sum -= grid[botx][boty];
                layer_sum -= grid[leftx][lefty];
                layer_sum -= grid[rightx][righty];

                sum = layer_sum;
                maxi = max(maxi, sum);
            }
        }
    }

    cout << maxi << '\n';
    return 0;
}


//93601834359 <- ans
