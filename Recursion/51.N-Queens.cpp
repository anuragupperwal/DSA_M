class Solution {
public:

    bool isSafe(int n, vector<string> chessBoard, int i, int j) {
        int row = i, col = j;
        //upper left diagonal
        while(row>=0 && col >=0){
            if(row<n && chessBoard[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row=i;
        col=j;
        //lower left diagonal
        while(row<n && col>=0) {
            if(col<n && chessBoard[row][col] == 'Q') return false;
            row++;
            col--;
        }

        //same row leftwards
        row = i;
        col = j;
        while(col>=0){
            if(col<n && chessBoard[row][col] == 'Q') return false;
            col--;
        }

        return true;
    }

    void rec(int n, vector<string>& chessBoard, vector<vector<string>>& res, int j) {
        if(j == n) {
            res.push_back(chessBoard);
            return;
        }
        for(int i=0; i<n; i++) {
            if(isSafe(n, chessBoard, i, j)) {
                chessBoard[i][j] = 'Q';
                rec(n, chessBoard, res, j+1);
                chessBoard[i][j] = '.';
            }
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> chessBoard(n, s);
        vector<vector<string>> res;
        rec(n, chessBoard, res, 0);

        return res;
    }
};

