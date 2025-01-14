#define ll long long 

class Solution {
public:
    ll sumFormula(ll val, ll midSum) {
        return val*midSum - val*(val+1)/2 ;
    }
    bool maxSumFound(int n, int index, int maxSum, ll curSum){
        //left sum
        ll leftCount = min(curSum-1, (ll)index);
        ll leftSum = sumFormula(leftCount, curSum);
        leftSum += max(index - (curSum-1), (ll)0); // for extra 1

        //right sum
        ll rightCount = min(curSum-1, (ll)n-index-1);
        ll rightSum = sumFormula(rightCount, curSum);
        rightSum += max((n-index-1) - (curSum-1), (ll)0);// for extra 1

        //calc and return result
        if( (leftSum + rightSum + curSum) <= maxSum ) return true;
        return false;
    }
    int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum;
        int res;

        while(left <= right) {
            ll curSum = left + (right-left)/2;

            if(maxSumFound(n, index, maxSum, curSum)){
                res = max((ll)res, curSum);
                left = curSum+1;
            }
            else right = curSum-1;
        }

        return res;
    }
};