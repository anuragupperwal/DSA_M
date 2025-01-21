class Solution {
public:
    int countPairs(vector<int>& nums, int n, int diff, int p) {
        int count=0;
        for(int i=0; i<n-1; ) {
            if( (nums[i+1] - nums[i] )<= diff) {
                count++;
                i+=2;
            }
            else i++;
        }
        return (count >= p);
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums[n-1] - nums[0];
        int res = 0;

        while(left <= right) {
            int midDifference = left + (right-left)/2;
            if(countPairs(nums, n, midDifference, p)) {
                res = midDifference;
                right = midDifference-1;
            }
            else left = midDifference+1;
        }

        return res;
    }
};