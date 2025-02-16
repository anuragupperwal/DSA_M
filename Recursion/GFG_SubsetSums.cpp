class Solution {
  public:
    void rec(vector<int> arr, vector<int>& res, int i, int sum) {
        if(i == arr.size()) {
            res.push_back(sum);
            return;
        } 
        rec(arr, res, i+1, sum+arr[i]);
        rec(arr, res, i+1, sum);
    }
    
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> res;
        rec(arr, res, 0, 0);
        
        return res;    
    }
};