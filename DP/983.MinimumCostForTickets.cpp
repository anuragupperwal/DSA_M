class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int n, vector<int>& dp){
        if(n >= days.size()) return 0;

        if(dp[n] != -1) return dp[n];

        int oneDay = costs[0] + solve(days, costs, n+1, dp);
        int i;
        //7days
        for(i = n; i<days.size() && days[i] < days[n]+7; i++);

        int sevenDays = costs[1] + solve(days, costs, i, dp);

        //30days
        for(i = n; i<days.size() && days[i] < days[n]+30; i++);

        int thirtyDays = costs[2] + solve(days, costs, i, dp);

        return dp[n] = min(min(oneDay, sevenDays), thirtyDays);
    
    }

    int tabu(vector<int>& days, vector<int>& costs){
        int n = days.size();
        vector<int> dp(n+1, 0);

        for(int k=n-1; k>=0; k--) {
            int oneDay = costs[0] + dp[k+1];
            int i;
            //7days
            for(i = k; i<n && days[i] < days[k] + 7; i++);

            int sevenDays = costs[1] + dp[i];

            //30days
            for(i = k; i<n && days[i] < days[k] + 30; i++);

            int thirtyDays = costs[2] + dp[i];

            dp[k] = min(min(oneDay, sevenDays), thirtyDays);

        }

        return dp[0];
    }


    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int> dp(days.size(), -1);
        // return solve(days, costs, 0, dp);
        return tabu(days, costs);
    }
};