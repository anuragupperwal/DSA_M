class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum=0;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            bool left = false, right = false;
            if(i-k >= 0){
                if(nums[i] > nums[i-k]) left = true;
            }
            else left = true;
            if(i+k <n) {
                if(nums[i] > nums[i+k]) right = true;
            }
            else right = true;
            if(left && right) sum+=nums[i];
        }

        return sum;
    }
};