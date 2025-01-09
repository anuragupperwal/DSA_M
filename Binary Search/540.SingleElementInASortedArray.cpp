class Solution {
public:

    //using binary search
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n==1)return nums[0];
        int start=0, end=n-1;
        while(start<=end) {
            int mid = start + (end-start)/2;

            if(mid==0 || mid==n-1){
                return nums[mid];
            }
            else{
                if(nums[mid-1] != nums[mid] && nums[mid+1] != nums[mid]) return nums[mid];
                else if(nums[mid-1] == nums[mid]) {
                    if(((n-1)-mid)%2==0) end = mid-2;
                    else start = mid+1;
                }
                else{
                    if(((n-1)-mid+1)%2 == 0) end=mid-1;
                    else start = mid+2;
                }
            }
        }
        return -1;
    }



    // //using bitwise operator
    // int singleNonDuplicate(vector<int>& nums) {
    //     int res = 0;
    //     for(int i=0; i<nums.size(); i++) res = res^nums[i];
    //     return res;
    // }
};