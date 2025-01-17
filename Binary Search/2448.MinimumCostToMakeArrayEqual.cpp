#define ll long long

class Solution {
public:
    ll ope(int mid, vector<int>& nums, int n, vector<int>& cost){
        ll costOpe=0;
        for(int i=0; i<n; i++) costOpe += (ll)abs(nums[i] - mid)*cost[i];
        return costOpe;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        int left = *min_element(nums.begin(), nums.end());
        int right= *max_element(nums.begin(), nums.end());
        ll resCost=0;

        while(left <= right) {
            int mid = left + (right-left)/2;
    
            ll midOpe = ope(mid, nums, n, cost) ;
            ll nextToMidOpe = ope(mid+1, nums, n, cost);

            if(midOpe < nextToMidOpe) {
                resCost = midOpe;
                right = mid-1;
            }
            else {
                resCost = nextToMidOpe;
                left = mid+1;
            }
        }

        return resCost;
    }
};