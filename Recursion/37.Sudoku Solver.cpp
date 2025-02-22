class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, int val) {
        for(int i=0; i<9; i++) {
            if(board[i][col] == val) return false;
            if(board[row][i] == val) return false;
            //still can't visualise how to compute this formula to check other cells in the 3x3 grip in the sudoku
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val) return false; 
        }
        return true;
    }
    bool fun(vector<vector<char>>& board){
        int n = board.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == '.') {
                    
                    for(char val='1'; val<='9'; val++) {
                        if(isValid(board, i, j, val)){
                            board[i][j] = val;
                            if(fun(board)==true) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board){
        fun(board);
    }
};