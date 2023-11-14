class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m  = box.size();
        int n = box[0].size();

        vector<vector<char>> ans(n, vector<char>(m));

        for(int i = 0; i < n; i++)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                ans[i][m - 1 - j] = box[j][i];
            }
        }

        for(int i = 0; i < m; i++)
        {
            int pos = n - 1;
            for(int j = pos; j >=0 ; j--)
            {
                if(ans[j][i] == '*')
                    pos = j -1;
                else if (ans[j][i] == '#')
                {
                    ans[j][i] = '.';
                    ans[pos][i] = '#';
                    pos--;
                }
            }
        }

        return ans;
    }
};