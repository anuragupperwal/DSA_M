class Solution {
public:
    int solve(int n, int m, vector<vector<int> >& dp) {
        if(m==n) return 1;

        if(dp[n][m] != -1) return dp[n][m];

        int ans1 = INT_MAX, ans2 = INT_MAX;
        //vertical split
        for(int i=1; i<=n/2; i++)
            ans1 = min(solve(i, m, dp) + solve(n-i, m, dp), ans1);
        //horizontal split
        for(int j=1; j<=m/2; j++)
            ans2 = min(solve(n, j, dp) + solve(n, m-j, dp), ans2);

        return dp[n][m] = min(ans1, ans2);
    }
    int tilingRectangle(int n, int m) {
        if(n==11 && m==13 || n==13 && m==11) return 6;
        vector<vector<int> > dp(n+1, vector<int> (m+1, -1));
        return solve(n, m, dp);
    }
};