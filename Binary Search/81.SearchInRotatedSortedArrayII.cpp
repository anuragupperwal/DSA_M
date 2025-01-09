class Solution {
public:
    bool BS(vector<int>& arr, int start, int end, int k) {
        int n = arr.size();
        while(start <= end) {
            int mid = start + (end-start)/2;

            if(arr[mid] == k) return true;
            else if(arr[mid] < k) start = mid+1;
            else end = mid-1;
        }

        return false;
    }

    bool search(vector<int>& arr, int k) {
        int n = arr.size();
        int start = 0, end = n-1;


        //find rotation pivot idx
        while(start < end) {
            //to get rid to repeating terms (simply skipping them)
            while(start<end && arr[start] == arr[start+1]) start++;
            while(start<end && arr[end] == arr[end-1]) end--;
            int mid = start + (end-start)/2;

            if(arr[mid] < arr[end]) end = mid;
            else start = mid+1;
        }

        //check for the k val in arr
        int leftCheck=false, rightCheck=false;
        leftCheck = BS(arr, 0, end-1, k);
        if(leftCheck) return true;
        rightCheck = BS(arr, end, n-1, k);
        return rightCheck;
    }
    
};