class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        vector<int> mp(n, -1);
        vector<string> board(n, string(n, '.'));
        vector<vector<string> > res;
        
        solveNQueensHelper(n, 0, mp, board, res);
        
        return res;
    }
    
    void solveNQueensHelper(int n, int c, vector<int> &mp, vector<string> &board, vector<vector<string> > &res){
        if(c == n){
            res.push_back(board);
            return;
        }
        for(int r = 0; r < n; r++){
            if(checkValid(r, c, mp)){
                mp[c] = r;
                board[r][c] = 'Q';
                solveNQueensHelper(n, c+1, mp, board, res);
                board[r][c] = '.';
            }
        }
    }

    bool checkValid(int r, int c, vector<int> &mp){
        for(int i = 0; i < c; i++){
            if(abs(mp[i] - r) == (c - i) || mp[i] == r)
                return false;
        }
        return true;
    }
};
