
class Solution {
public:

    //attempt 2
    int binarySearch(vector<int>& nums, int start, int end, int k) {
        int n = nums.size();

        while(start<=end) {
            int mid = start + (end-start)/2;

            if(nums[mid] == k) return mid;
            else if(nums[mid] > k) end = mid-1;
            else start = mid+1;
        }
        return -1;
    }

    int search(vector<int>& nums, int k) {
        int n = nums.size();

        int start = 0, end = n-1;
        while(start<=end) {
            int mid = start + (end-start)/2;

            if(nums[mid] < nums[end]) end = mid;
            else start = mid+1;
        }
        
        int leftCheck=-1, rightCheck = -1;
        leftCheck = binarySearch(nums, 0, end-1, k);
        rightCheck = binarySearch(nums, end, n-1, k);

        return (leftCheck != -1)? leftCheck: rightCheck;
    }


    //Correct attempt 1
    //deleted
};