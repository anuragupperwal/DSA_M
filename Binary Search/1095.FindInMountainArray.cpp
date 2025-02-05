/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int left = 0, right = n-1;

        //BS for finding peak index
        int peakIdx;
        while(left <= right) {
            int mid = left + (right-left)/2;

            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                left = mid+1;
            else 
                right = mid-1;
        }
        peakIdx = left;
        cout<<peakIdx<<endl;

        //BS on left half first then right half.
        left = 0, right = peakIdx;
        while(left <= right) {
            int mid = left + (right-left)/2;
            int val = mountainArr.get(mid);

            if(val == target) return mid;
            else if(val < target) left = mid+1;
            else right = mid-1;
        }

        left = peakIdx, right = n-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            int val = mountainArr.get(mid);

            if(val == target) return mid;
            else if(val < target) right = mid-1;
            else left = mid+1;
        }

        return -1;
    }
};