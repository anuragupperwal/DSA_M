class Solution {
public:
    // int fun(vector<int>& cost, int n, vector<int> dp){
    //     if(n<0) return 0;
    //     if(n==0 || n==1) return cost[n-1];

    //     if(dp[n] != -1) return dp[n];

    //     int one = cost[n] + fun(cost, n-1, dp);
    //     int two = cost[n] + fun(cost, n-2, dp);
       

    //     return dp[n] = min(one, two);
    // }


    int tabu(vector<int>& cost, int n){
        vector<int> dp(n+1, 0); 

        for(int i=1; i<=n; i++){  
            if(i==0 || i==1) dp[i] = cost[i-1];     
            else dp[i] = cost[i-1] + min( dp[i-1], dp[i-2]);
        }

        return min(dp[n], dp[n-1]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n+1, -1);
        // return fun(cost, n, dp); //doesn't work
        return tabu(cost, n);
    }
};