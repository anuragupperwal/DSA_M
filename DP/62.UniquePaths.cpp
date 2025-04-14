class Solution {
public:
    int solve(int m, int n, vector<vector<int> > dp) {
        if(m<0 || n<0) return 0;
        if(m==0 && n==0) return 1;

        if(dp[m][n] != -1) return dp[m][n];

        int up = 0;
        if(m-1>=0) up = solve(m-1, n, dp);
        int left = 0;
        if(n-1>=0) left = solve(m, n-1, dp);

        return dp[m][n] = (left + up);
    }
    
    int solveTabu(int m, int n) {
        vector<vector<int> > dp(m, vector<int> (n, 0));

        dp[0][0] = 1;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) continue; // can't let this one run with update code. Also need to continue here to go ahead and skip this value. Need to start from 0 only bcoz there is a path there as well.
                else {
                    int up = 0;
                    if(i-1>=0) up = dp[i-1][j];
                    int left = 0;
                    if(j-1>=0) left = dp[i][j-1];

                    dp[i][j] = (left + up);
                }
            }
        }
        return dp[m-1][n-1];
    }

       
    int solveTabuOpti(int m, int n) {
       vector<int> prev(n, 0), cur(n, 0);

        cur[0] = 1;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) continue; 
                else {
                    int up = 0;
                    if(i-1>=0) up = prev[j];
                    int left = 0;
                    if(j-1>=0) left = cur[j-1];

                    cur[j] = (left + up);
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
    
    int uniquePaths(int m, int n) {
        // vector<vector<int> > dp(m+1, vector<int> (n+1, -1));
        // return solve(m-1, n-1, dp);
        // return solveTabu(m, n);
        return solveTabuOpti(m, n);
    }
};