class Solution {
public:
    int fun(vector<vector<int>>& grid, int m, int n,  vector<vector<int> >& dp) {
        if(m==0 && n==0) return grid[0][0];
        if(m<0 || n<0) return 1e9;
        if(dp[m][n] != -1) return dp[m][n];

        int right = (grid[m][n]+ fun(grid, m-1, n, dp));
        int down =  (grid[m][n] + fun(grid, m, n-1, dp));
        int val = min(right, down);

        return dp[m][n] = val;
    }

    int tabu(vector<vector<int>>& grid, int m, int n) {
        vector<vector<int> > dp(m, (vector<int> (n, 0)));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) dp[0][0] = grid[0][0];
                else {
                    int right = 1e9, down = 1e9;
                    if(i-1>=0) right = (grid[i][j]+ dp[i-1][j]);
                    if(j-1>=0) down = (grid[i][j] + dp[i][j-1]);
                    int val = min(right, down);

                    dp[i][j] = val;
                }
            }
        }

        return dp[m-1][n-1];
    }



    int minPathSum(vector<vector<int>>& grid) {
        int m =  grid.size(), n = grid[0].size();
        // vector<vector<int> > dp(m, (vector<int> (n, -1)));
        // return fun(grid, m-1, n-1, dp);
        return tabu(grid, m, n);
    }
};