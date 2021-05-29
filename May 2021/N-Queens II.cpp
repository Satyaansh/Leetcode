class Solution {
public:
    bool isSafe(vector<string> board, int row, int col, int n){
        for(int i = 0; i < n; i++)
            if(board[i][col] == 'Q')
                return false;
        
        for(int i = 0; i < n; i++)
            if(board[row][i] == 'Q')
                return false;
        
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if(board[i][j] == 'Q')
                return false;
        
        for(int i = row, j = col; i < n && j >= 0; i++, j--)
            if(board[i][j] == 'Q')
                return false;
        
        return true;
    }
    void nQueens(vector<string> board, int col, int n, int &ans){
        if(col == n){
            ans++;
            return;
        }
        for(int i = 0; i < n; i++){
            if(board[i][col] == '.' && isSafe(board, i, col, n)){
                board[i][col] = 'Q';
                nQueens(board, col + 1, n, ans);
                board[i][col] = '.';
            }
        }
        return;
    }
    
    int totalNQueens(int n) {
        if(n == 1)
            return n;     
        string temp = "";
        for(int i = 0; i < n; i++)
            temp += '.';
        vector<string> board(n, temp);
        int col = 0, ans = 0;
        nQueens(board, col, n, ans);
        return ans;
    }
};
