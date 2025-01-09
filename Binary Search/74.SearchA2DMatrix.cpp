class Solution {
public:
    //using binary search
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int start = 0, end = n*m-1;
        while(start<=end) {
            int mid = start + (end-start)/2;
            int val = matrix[mid/n][mid%n];

            if(val == target) return true;
            else if(val > target) end = mid-1;
            else start = mid+1;

        }
        
        return false;
    }


    // //Using a general method
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     bool found=false;
    //     int i=0, j=n-1;
    //     while(!found && i<m && j>=0){
    //         if(matrix[i][j] == target) {cout<<"found\n"; found=true; return true;}
    //         else if(matrix[i][j] < target) {i++; cout<<"left\n";}
    //         else {j--; cout<<"down\n";}
    //     }

    //     return false;
    // }



    // //First attempt
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int row = matrix.size();
    //     int col = matrix[0].size();

    //     int start = 0, end = row*col-1;
    //     int mid = start + (end-start)/2;

    //     while(start<=end) {
    //         int ele = matrix[mid/col][mid%col];

    //         if(ele == target) return 1;
    //         if(ele < target) start = mid+1;
    //         else end = mid-1;
    //         mid = start + (end-start)/2;
    //     }

    //     return 0;
    // }
};