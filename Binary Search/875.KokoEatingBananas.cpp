class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1, right=INT_MIN;
        for(int i=0; i<n; i++) right = max(right, piles[i]);

        while(left < right) {
            int mid = left + (right-left)/2;

            int hours=0;
            for(int i=0; i<n; i++) {
                hours+=(piles[i]/mid);
                hours += (piles[i]%mid > 0)? 1:0;
            }

            if(hours <= h) right = mid;
            else left = mid+1;
        }
        return right;
    }
};