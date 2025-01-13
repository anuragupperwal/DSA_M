class Solution {
public:

    bool isValid(vector<int>& nums, int curMax, int n) {
        vector<long long> arr(nums.begin(), nums.end()); //to make sure the changes we are making stays for the curMax only and we get original array for all the maxes.
        for(int i=0; i<n-1; i++) {
            if(arr[i] > curMax) return false; //to check at each element if greater than curMax then return not the right expected max.

            long long buff= curMax - arr[i]; 
            arr[i+1] -=buff; //update value of the next element 
        }
        return (arr[n-1] <= curMax); //check for the last element as no right ele to modify. All prior are true.
    } 
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right=INT_MIN, res=0;
        for(int i=0; i<n; i++) right = max(right, nums[i]);

        while(left <= right) {
            int curMax = left + (right-left)/2;

            if(isValid(nums, curMax, n)){
                res = curMax;
                right = curMax-1; //if valid answer found decrease to find more tighter answer.
            }
            else left = curMax+1; //in case of wrong answer

        }
        return res;
    }
};