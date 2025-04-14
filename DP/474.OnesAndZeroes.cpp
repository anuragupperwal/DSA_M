class Solution {
public:
    int solve(vector<string> strs, int m, int n, int idx, vector<pair<int, int> >& a, vector<vector<vector<int> > >& dp) {
        if(idx<0) return 0;
        if(m==0 && n==0) {
            return 0;
        }

        if(dp[idx][m][n] != -1) return dp[idx][m][n];

        int take=0;
        if(m - a[idx].first >=0 && n - a[idx].second >=0) {
            take = 1 + solve(strs, m-a[idx].first, n-a[idx].second, idx-1, a, dp);
        }
        int notTake = solve(strs, m, n, idx-1, a, dp);

        return dp[idx][m][n] = max(take, notTake);
    }

    int solveTabu(vector<string> strs, int m, int n, int idx, vector<pair<int, int> >& a) {
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for(int i=1; i<=idx; i++) {
            for(int j=0; j<=m; j++) {
                for(int k=0; k<=n; k++) {
                    int take=0;
                    if(j - a[i-1].first >=0 && k - a[i-1].second >=0) {
                        take = 1 + dp[i-1][j-a[i-1].first][k-a[i-1].second];
                    }
                    int notTake = dp[i-1][j][k];

                    dp[i][j][k] = max(take, notTake);
                }
            }
        }
        return dp[idx][m][n];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int> > temp, a;
        for(int i=0; i<strs.size(); i++) {
            int ones=0, zeros=0;
            for(int j=0; j<strs[i].length(); j++) {
                if(strs[i][j] == '1') ones++;
                else zeros++;
            }
            a.push_back(make_pair(zeros, ones));
        }
        // vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        // int res = solve(strs, m , n, strs.size()-1, a, dp);
        int res = solveTabu(strs, m , n, strs.size(), a);
        return res;
    }


// //   (Other approach) Understand this solution
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(const string& s : strs) {
            int ones = count(s.begin(), s.end(), '1');
            int zeros = s.length() - ones;

            for(int i = m; i >= zeros; --i) {
                for(int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};