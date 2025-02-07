class Solution {
public:

    // //method 1 
        // - O(nlogn)
    // int specialArray(vector<int>& nums) {
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());

    //     for(int i=0; i<=n; i++) {
    //         int idx = lower_bound(nums.begin(), nums.end(), i)-nums.begin();
    //         int count = n - idx;
    //         if(count==i) return count;
    //     }
    //     return -1;
    // }


    // //method 2 
        // - O(nlogn) because of sorting otherwise improved as now using two BS internally other than sorting it's O(log^2n)
    // int specialArray(vector<int>& nums) {
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());

    //     int left = 0, right = n;
    //     while(left <= right){
    //         int midVal = left + (right-left)/2;

    //         int idx = lower_bound(nums.begin(), nums.end(), midVal)-nums.begin();
    //         int count = n - idx;
    //         if(count > midVal) 
    //             left = midVal+1;
    //         else if(count < midVal)
    //             right = right = midVal-1;
    //         else 
    //             return midVal;
    //     }
    //     return -1;
    // }

    //method 3 
        // - using summation - O(n)
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> occurCount(n+1);
        for(int i=0; i<n; i++) {
            if(nums[i] >n) occurCount[n]+=1;
            else occurCount[nums[i]]+=1;
        }
        for(int i=n-1; i>=0; i--) {
            occurCount[i] += occurCount[i+1]; 
        }

        for(int i=0; i<=n; i++) {
            if(occurCount[i] == i) return i;
        }
        return -1;
    }

};