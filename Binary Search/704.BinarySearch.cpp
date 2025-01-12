class Solution {
public:
    //recursive
    int BS(vector<int>& nums, int left, int right, int target) {
        if(left > right) return -1;
        int mid = left + (right-left)/2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) return BS(nums, left, mid-1, target);
        else return BS(nums, mid+1, right, target);
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return BS(nums, 0, n-1, target);
    }
};