class Solution {
public:
    //rec + memo ----- but TLE, so Tabu
    int fun(vector<vector<int>>& tri, int n, int m, vector<vector<int> >& dp) {
        if(n == 0 && m==0) return tri[0][0];
        if(n==0 && m>0) return INT_MAX;

        if(dp[n][m] != -1) dp[n][m];

        int upLeft = INT_MAX;
        if(m-1 >= 0) upLeft = tri[n][m] + fun(tri, n-1, m-1, dp);
        int up = INT_MAX;
        if(m <= n-1) up = tri[n][m] + fun(tri, n-1, m, dp);

        return dp[n][m] = min(upLeft, up);
    }

    int tabu(vector<vector<int>>& tri, int n, int m) {
        vector<vector<int> > dp(n, (vector<int> (m, 0)));

        if(n==1) return tri[n-1][m-1];

        dp[0][0] = tri[0][0];

        for(int i=1; i<n; i++){
            for(int j=0; j<=i; j++) {
                int upLeft = INT_MAX;
                if(j-1 >= 0) upLeft = tri[i][j] + dp[i-1][j-1];
                int up = INT_MAX;
                if(j <= i-1) up = tri[i][j] + dp[i-1][j];

                dp[i][j] = min(upLeft, up);
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        int res=1e8;
        // vector<vector<int> > dp(n+1, (vector<int> (m+1, -1)));
        // for(int i=m-1; i>=0; i--)
        //     res = min(res, fun(triangle, n-1, i, dp));

        res = tabu(triangle, n, m);
        return res;
    }
};