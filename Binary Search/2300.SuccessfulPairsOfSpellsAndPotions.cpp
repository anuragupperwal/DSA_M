class Solution {
public:
    //BS
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(), m=potions.size();
        vector<int> res;
        sort(potions.begin(), potions.end());


        for(int i=0; i<n; i++) {
            int left = 0, right = m-1;
            int count=0;
            long long minPotionVal = ceil((1.0*success)/spells[i]); //mul by 1.0 to make it float so that we can take ceil and get the correct value.
            if(minPotionVal > potions[m-1]) {
                res.push_back(0);
                continue; //if min value is greater than max potion value for this spell then no benefit in comparing.
            }
            while(left < right) {
                int mid = left + (right-left)/2;
                if(potions[mid] >= minPotionVal) right = mid; //spells[i]*potopns[mid] should be >= success. To reduce problem with space instead divide it.
                else left = mid+1;
            }
            if(m-right == 1) {
                if(potions[m-1] >= (minPotionVal)) res.push_back(1);
                else res.push_back(0);
            }
            else res.push_back(m-right);
        }

        return res;
    }

    // //brute force
    // vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    //     int n = spells.size(), m = potions.size();
    //     vector<int> res;
    //     for(int i=0; i<n; i++) {
    //         int val = 0;
    //         for(int j=0; j<m; j++) {
    //             if((long long)spells[i]*potions[j] >= success) val++;
    //         }
    //         res.push_back(val);
    //     }
    //     return res;
    // }
};