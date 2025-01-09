class Solution {
public:

    int findMin(vector<int>& arr) {
        int start = 0, end = arr.size()-1;
        int mid = start + (end - start) / 2;

        while(start<end) {
            if(arr[mid] > arr[end])
                start = mid + 1;
            else
                end = mid;
            mid = start + (end - start) / 2;
        }
        return arr[start];
    }

};