class Solution {
public:
    //approach 1 - using BS
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        int totalProf=0;

        vector<pair<int, pair<int, int> > > diffProf;
        int maxSoFar = -1;
        //to create the nested vector pair
        for(int i=0; i<n; i++) {
            diffProf.push_back({difficulty[i], {profit[i], 0}});
        }

        sort(diffProf.begin(), diffProf.end());

        //to update the max profit so far after sorted as per difficulty
        for(int i=0; i<n; i++) {
            maxSoFar = max(maxSoFar, diffProf[i].second.first);
            diffProf[i].second.second = maxSoFar;
        }

        //main binary search for all n ele
        for(int i=0; i<m; i++) {
            int sum=0;
            int left = 0, right = n-1;
            while(left <= right) {
                int mid = left + (right-left)/2;

                if(diffProf[mid].first <= worker[i]){
                    int maxVal = diffProf[mid].second.second;
                    sum = maxVal;
                    left = mid+1;
                }
                else 
                    right = mid-1;
            }
            totalProf += sum;
        }
        return totalProf;
    }
};