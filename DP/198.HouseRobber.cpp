class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int>& dp) {
        if(n == 0) return nums[0];
        if(n<0) return 0;

        if(dp[n] != -1) return dp[n];

        int take=INT_MIN;
        take = nums[n] + solve(nums, n-2, dp);
        int notTake = solve(nums, n-1, dp);

        return dp[n] = max(take, notTake);
    }
    int solveTabu(vector<int>& nums, int n) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        for(int i=1; i<n; i++) {
            int take = nums[i];
            if(i>1) take +=  dp[i-2];
            int notTake = dp[i-1];

            dp[i] = max(take, notTake);
        }

        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size()+1, -1);
        // return solve(nums, nums.size()-1, dp);
        return solveTabu(nums, nums.size());
    }
};