class Solution {
public:
    void powerSet(vector< vector<int> >& res, vector<int>& arr, vector<int>& list, int i) {
        res.push_back(list); //O(n)
        for(int j=i; j<arr.size(); j++) {
            if(j!=i && arr[j] == arr[j-1]) continue; //j!=i means that if it's not the first occurance of that particular value then we have to skip. Basically both fo the repetation of the elements.

            list.push_back(arr[j]);
            powerSet(res, arr, list, j+1);
            list.pop_back();
        }
    }
        
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> list;
        sort(nums.begin(), nums.end());
        powerSet(res, nums, list, 0);
        return res;
    }
};
