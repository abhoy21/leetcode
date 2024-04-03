class Solution {
public:
    bool func(vector<vector<char>>& board, string word, int i, int j, int n, int m, int k){
        if(k == word.size()) return true;
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[k]) return false;
        char ch = board[i][j];
        board[i][j] = '1';

        bool up = func(board, word, i+1, j, n, m, k+1);
        bool down = func(board, word, i-1, j, n, m, k+1);
        bool left = func(board, word, i, j-1, n, m, k+1);
        bool right = func(board, word, i, j+1, n, m, k+1);

        board[i][j] = ch;

        return up || down || left || right;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(func(board, word, i, j, n, m, 0)) return true;
            }
        }        

        return false;
    }
};