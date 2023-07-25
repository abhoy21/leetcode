class Solution {
public:
        bool check(int i, int j, vector<vector<char>>& board,int n, int m, string word,int k)
    {
        if(k==word.size()) return true;
        if(i<0||j<0||i==n||j==m||board[i][j]!=word[k]) return false;
        char ch = board[i][j];
        board[i][j] = '1';
        bool chk1 = check(i+1,j,board,n,m,word,k+1);
        bool chk2 = check(i,j+1,board,n,m,word,k+1);
        bool chk3 = check(i-1,j,board,n,m,word,k+1);
        bool chk4 = check(i,j-1,board,n,m,word,k+1);
        board[i][j] = ch;
        return chk1||chk2||chk3||chk4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(check(i,j,board,n,m,word,0)) return true;
            }
        }
        
        return false;
    }
};