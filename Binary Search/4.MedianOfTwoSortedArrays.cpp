class Solution {
public:
    //attempt 1: accepted but slow 
    double bruteForce(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        int m = nums1.size(), n = nums2.size();
        int i=0, j=0;

        while(i < m && j<n) {
            if(nums1[i] < nums2[j]) {
                vec.push_back(nums1[i]);
                i++;
            }
            else {
                vec.push_back(nums2[j]);
                j++;
            }
        }

        while(i<m) {vec.push_back(nums1[i]); i++;}
        while(j<n) {vec.push_back(nums2[j]); j++;}


        if( (n+m)%2 == 0 ) {
            return (double)(vec[(n+m)/2] + vec[((n+m)/2) -1])/2;
        }
        return vec[(n+m)/2];
    }

    
    // attempt 2: O(1) space solution
    double constSpaceSol(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int resIdx1=0, resIdx2=0, ele1=-1, ele2=-1;
        resIdx1 = (m+n)/2-1;
        resIdx2 = (m+n)/2;

        int i=0, j=0, count=0;;

        while(i < m && j<n) {
            if(nums1[i] < nums2[j]) {
                if(count == resIdx1) 
                    ele1 = nums1[i];
                if(count == resIdx2) 
                    ele2 = nums1[i];
                i++;
            }
            else {
                if(count == resIdx1) 
                    ele1 = nums2[j];
                if(count == resIdx2)
                    ele2 = nums2[j];
                j++;

            }
            count++;
        }

        while(i<m) {
            if(count == resIdx1) 
                ele1 = nums1[i];
            if(count == resIdx2) 
                ele2 = nums1[i];
            i++;
            count++;
        }
        while(j<n) {
            if(count == resIdx1) 
                ele1 = nums2[j];
            if(count == resIdx2)
                ele2 = nums2[j];
            j++;
            count++;
        }


        if( (n+m)%2 == 0 ) {
            return (double)(ele1 + ele2)/2;
        } 
        return ele2;
    }

    //Approach 3: Binary Search
    bool isValidPartition(vector<int>& nums1, vector<int>& nums2, int midPartitionVal, int m, int n, int medianIdx) {
        int n1Left = (midPartitionVal > 0) ? nums1[midPartitionVal - 1] : INT_MIN;
        int n1Right = (midPartitionVal < m) ? nums1[midPartitionVal] : INT_MAX;
        int n2Left = (medianIdx - midPartitionVal > 0) ? nums2[medianIdx - midPartitionVal - 1] : INT_MIN;
        int n2Right = (medianIdx - midPartitionVal < n) ? nums2[medianIdx - midPartitionVal] : INT_MAX;

        return n1Left <= n2Right && n2Left <= n1Right;
    }
    double BS(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n) 
            return BS(nums2, nums1); // binary search the smaller array for efficiency
        

        int median;
        int left=0, right=m;
        int medianIdx = (m+n+1)/2;

        while(left <= right) {
            int midPartitionVal = left + (right-left)/2;

            if(isValidPartition(nums1, nums2, midPartitionVal, m, n, medianIdx)) {
                int n1Left = (midPartitionVal > 0)? nums1[midPartitionVal-1] : INT_MIN;
                int n2Left = (medianIdx - midPartitionVal > 0)? nums2[medianIdx - midPartitionVal -1] : INT_MIN;

                if((m+n)%2 == 1)
                    return max(n1Left, n2Left);
                else {
                    int n1Right = (midPartitionVal < m)? nums1[midPartitionVal] : INT_MAX;
                    int n2Right = (medianIdx - midPartitionVal < n)? nums2[medianIdx - midPartitionVal] : INT_MAX;
                    return ((max(n1Left, n2Left)) + (min(n1Right, n2Right))) / 2.0;
                }
            }
            else if(midPartitionVal > 0 && nums1[midPartitionVal] > nums2[medianIdx - midPartitionVal]) //basically agar n1 ki left value is greater than n2 ke right ki first value se so we need to move our mid on n1 towards left i.e. r = m-1;
                right = midPartitionVal -1;
            else //i.e. if last val of n2 left is greater than the first val of n1 right then move the left to mid+1
                left = midPartitionVal+1;
        }

        return 0;
        
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // return bruteForce(nums1, nums2);
        // return constSpaceSol(nums1, nums2);
        return BS(nums1, nums2);
    }
};