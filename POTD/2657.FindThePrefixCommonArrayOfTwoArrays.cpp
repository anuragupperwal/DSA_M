class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> AVec;
        vector<int> res;

        for(int j=0; j<A.size(); j++) {
            AVec.insert(A[j]);
            int count=0;
            for(int i=0; i<=j; i++){
                if(AVec.find(B[i]) != AVec.end()) {
                    count++;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};