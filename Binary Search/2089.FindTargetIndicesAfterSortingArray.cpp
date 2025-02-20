class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int n = nums.size();
        int left = 0, right = n-1;
        while(left <= right) {
            int mid = left + (right-left)/2;

            if(nums[mid] == target) {
                int i = mid, j=mid;
                res.push_back(i);
                int startIdx, endIdx;
                while(i<n-1 && nums[i] == nums[i+1]){
                    i++;
                    res.push_back(i);
                }
                while(j>0 && nums[j] == nums[j-1]){
                    j--;
                    res.push_back(j);
                }
                break;
            }
            else if(nums[mid] > target) right = mid-1;
            else left = mid+1;
        }   

        sort(res.begin(), res.end());
        return res;
    }
};