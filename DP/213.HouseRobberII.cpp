class Solution {
public:
    int robber1Tabu(vector<int>& nums, int n) {
        vector<int> dp(n, 0);
        dp[0] = nums[0];

        for(int i=1; i<n; i++) {
            int take = nums[i];
            if(i>1) take += dp[i-2];
            int notTake = dp[i-1];

            dp[i] = max(take, notTake);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0]; 
        vector<int> nums1, nums2;
        for(int i=0; i<n; i++) {
            if(i==0) nums1.push_back(nums[i]);
            else if(i == n-1) nums2.push_back(nums[i]);
            else{
                nums1.push_back(nums[i]);
                nums2.push_back(nums[i]);
            }
        }
        int res1 = robber1Tabu(nums1, n-1);
        int res2 = robber1Tabu(nums2, n-1);

        return max(res1, res2);
    }
};