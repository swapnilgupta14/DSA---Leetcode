class Solution {
public:
    bool res = false;
    void solve(vector<vector<char>>& board, string &word, 
        vector<vector<int>>& check, int i, int j, int w_idx){
            if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return;
            if(check[i][j] == 1) return;
            if(board[i][j] != word[w_idx]) return;
            if(w_idx == word.size() - 1) {
                res = true;
                return;
            }
            check[i][j] = 1;
            solve(board, word, check, i-1, j, w_idx + 1);
            solve(board, word, check, i+1, j, w_idx + 1);
            solve(board, word, check, i, j+1, w_idx + 1);
            solve(board, word, check, i, j-1, w_idx + 1);
            check[i][j] = 0;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row_s = board.size();
        int col_s = board[0].size();
        vector<vector<int>> check(row_s, vector<int> (col_s, 0));
        for(int i = 0; i < row_s; ++i) {
            for(int j = 0; j < col_s; ++j) {
                solve(board, word, check, i, j, 0);
                if(res) return true;
            }
        }
        return false;
    }
};
