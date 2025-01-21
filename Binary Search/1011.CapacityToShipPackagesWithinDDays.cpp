class Solution {
public:
    bool isValid(vector<int>& weights, int days, int capacity, int n) {
        int count=0;
        long long sum = 0;
        for(int i=0; i<n; i++) {
            if (weights[i] > capacity) 
                return false;
            
            if(sum+weights[i] > capacity) {
                count++;
                sum = weights[i];
            }
            else 
                sum+=weights[i];

        }
        if (sum > 0) count++; //after last day if left

        return (count <= days);
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int res=0;
        while(left <= right) {
            int capacity = left + (right-left)/2;

            if(isValid(weights, days, capacity, n)){
                res = capacity;
                right = capacity-1;
            }
            else left = capacity+1;
        }
        return res;
    }
};