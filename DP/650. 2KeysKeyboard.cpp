class Solution {
public:
    int solve(int n, int cur, int cpyLen, vector<vector<int> >& dp) {
        if(n<=1) return 0;
        if(n<cur) return 1e8;
        if(n==cur) return 0;

        if(dp[cur][cpyLen] != -1) return dp[cur][cpyLen];

        int paste = 1 + solve(n, cur+cpyLen, cpyLen, dp);
        int copyPaste = 2 + solve(n, cur*2, cur, dp);

        return dp[cur][cpyLen] = min(copyPaste, paste);
    }

    // int solve(int n, int cur, int cpyLen) {
    //     vector<vector<int> > dp(n+1, vector<int> (n+1, 0));

    //     for(int i=0; i<n; i++) {
    //         for(int j=0; j<n; j++)
    //     }
    // }

    int minSteps(int n) {
        if(n==1) return 0; //this is the case which our function will always fail because it should be 0 and we return '1 + or more' always. So, handling that.
        vector<vector<int> > dp(n+1, vector<int> (n+1, -1));
        return solve(n, 1, 1, dp)+1;
    }
};