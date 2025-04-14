#include <iostream>
#include <vector>
using namespace std;

void solve(int n, int m, int k) {
    vector<vector<int>> grid(n, vector<int>(m));
    int color = 1;

    // Use a rotating color assignment that avoids adjacent repetition
    // Each color appears exactly (n * m / k) times
    int total = n * m;
    int each = total / k;
    vector<int> counts(k + 1, 0); // counts for each color

    // Fill the grid with checkerboard-style coloring
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // Try assigning color in order, skipping those already used up
            while (counts[color] >= each)
                color = (color % k) + 1;
            grid[i][j] = color;
            counts[color]++;
            color = (color % k) + 1;
        }
    }

    // Output the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << grid[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        solve(n, m, k);
    }
    return 0;
}