class Solution {
public:
    // int SSP(vector<int>& stones, int n, int sum, vector<vector<int>> dp) {
    //     if(sum == 0) return 1;
    //     if(n==0) return 0;
    //     // if(n==1) return (stones[n] == sum);

    //     if(dp[n][sum] != -1) return dp[n][sum];

    //     int take = 0;
    //     if(sum - stones[n-1] >=0) take = SSP(stones, n-1, sum - stones[n-1], dp);
    //     int notTake = SSP(stones, n-1, sum, dp);

    //     return dp[n][sum] = take || notTake;
    // }

    int tabu(vector<int>& stones, int n, int sum) {
        vector<vector<int>> dp(n+1, vector<int> (sum+1, 0));

        for(int i=0; i<=n; i++) 
            dp[i][0] = 1;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=sum; j++) {
                int take = 0;
                if(j - stones[i-1] >=0) take = dp[i-1][j-stones[i-1]];
                int notTake = dp[i-1][j];
                dp[i][j] = take || notTake;
            }
        }

        for(int i = dp[0].size()-1; i>=0; i--){
            if(dp[n][i] == true) return i;
        }
 
        return -1;
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum=0;
        for(int i=0; i<n; i++)
            sum+=stones[i];
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));

        // int halfClosestSum = SSP(stones, n, sum/2, dp);
        int halfClosestSum = tabu(stones, n, sum/2);
        int res = (sum-halfClosestSum) - halfClosestSum;
        return res;
    }
};