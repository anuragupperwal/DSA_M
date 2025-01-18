class Solution {
public:
    //new  better
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int left = 0, right= n-1;

        while(left<right) {
            int mid = left + (right-left)/2;

            if(arr[mid] <arr[mid+1]) left = mid+1;
            else right = mid;
        }

        return left;
    }


    // //old
    // int peakIndexInMountainArray(vector<int>& arr) {
    //     int n=arr.size();
    //     int start = 0, end = n-1;
    //     int mid = start + (end-start)/2, res;

    //     while(start<end) {
    //         if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1] ) {
    //             res = mid;
    //             break;
    //         }
    //         else if(arr[mid]<arr[mid+1]) start = mid+1;
    //         else end = mid-1;
    //         mid = start + (end-start)/2;
    //     }

    //     return res;
    // }
};