class Solution {
public:
    bool check(int i, int j, int m, int n, vector<vector<char>>& board, string word, int k)
    {
      if(k == word.size())
        return true;
      if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[k])
        return false;
      char ch = board[i][j];
      board[i][j] = '1';
      bool check1 = check(i+1, j, m, n, board, word, k+1);
      bool check2 = check(i, j+1, m, n, board, word, k+1);
      bool check3 = check(i-1, j, m, n, board, word, k+1);
      bool check4 = check(i, j-1, m, n, board, word, k+1);
      board[i][j] = ch;

      return check1 || check2 || check3 || check4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++)
        {
          for(int j = 0; j < m; j++)
          {
            if(check(i, j, m, n, board, word, 0)) return true;
          }
        }

        return false;
    }
};