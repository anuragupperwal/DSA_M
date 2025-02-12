class Solution {
public:
    vector<vector<int> > res;

    int rec(vector<int>& candidates, int t, vector<int>& list, int i, int n) {
        if(t == 0) {
            res.push_back(list);
            return 0;
        }
        if (i == candidates.size() || t < 0) {
           return 0;
        }

        list.push_back(candidates[i]);
        //take val
        rec(candidates, t-candidates[i], list, i, n);
        list.pop_back();
        //don't take val
        rec(candidates, t, list, i+1, n);

        return 0;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> list;
        rec(candidates, target, list, 0, candidates.size()-1);
        return res;
    }
};