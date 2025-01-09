class Solution {
public:
    int leftOccurrence(vector<int>& arr, int k) {
        int start = 0, end = arr.size()-1, res=-1;
        int mid = start + (end-start)/2;

        while(start<=end) {
            if(arr[mid] == k) {
                res = mid;
                end = mid-1;
            }
            else if(arr[mid] > k) end = mid-1;
            else start = mid+1;
            mid = start + (end-start)/2;
        }
        return res;
    } 
    int rightOccurrence(vector<int>& arr, int k) {
        int start = 0, end = arr.size()-1, res=-1;
        int mid = start + (end-start)/2;

        while(start<=end) {
            if(arr[mid] == k) {
                res = mid;
                start = mid+1;
            }          
            else if(arr[mid] > k) end = mid-1;
            else start = mid+1;
            mid = start + (end-start)/2;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int k)
    {
        vector<int> res;
        res.push_back(leftOccurrence(nums, k));
        res.push_back(rightOccurrence(nums, k));
        return res;
        
    }
};