// #define size 1e4

class Solution {
public:

    //didn't work. Checkout
    int approach2(int n, vector<int> dp){
        if(n<=0) return 0;

        if(dp[n] != -1) return dp[n];

        int res = n;
        for(int i=1; i*i<=n; i++){
            int sq = i*i;
            res = min(res, 1 + approach2(n-sq, dp));
        } 

        return dp[n] = res;
    }

    int unboundedKnapsack(vector<int>& PS, int idx, int sum, vector<vector<int> >& dp) {
        if(sum==10000) return 1;
        if(sum == 0) return 0;
        if(idx == 0) return INT_MAX;

        if(dp[idx][sum] != -1) return dp[idx][sum];

        int take = INT_MAX;
        if(sum - PS[idx-1] >=0) take = 1 + unboundedKnapsack(PS, idx, sum-PS[idx-1], dp);
        int notTake = unboundedKnapsack(PS, idx-1, sum, dp);

        return dp[idx][sum] = min(take, notTake);
    }
    int numSquares(int n) {
        vector<int> PS;
        for(int i=1; i<=n; i++){
            if(ceil(sqrt(i)) == floor(sqrt(i))) 
                PS.push_back(i);
        }

        int len = PS.size();
        vector<vector<int> > dp(len+1, vector<int> (n+1, -1));

        int count = unboundedKnapsack(PS, len, n, dp);
        // vector<int> dpVec(n+1, -1);
        // int count = approach2(n, dpVec  );
        return count;
    }
};