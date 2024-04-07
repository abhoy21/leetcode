class Solution {
public:
    bool func(string &s, int n, int cnt, int i, vector<vector<int>> &dp){
        if(i == n)
            return cnt == 0;
        
        if(dp[i][cnt] != -1)
            return dp[i][cnt];

        bool flag = false;

        if(s[i] == '*'){
            flag |= func(s, n, cnt+1, i+1, dp);
            if(cnt) flag |= func(s, n, cnt-1, i+1, dp);
            flag |= func(s, n, cnt, i+1, dp);
        }
        else{
            if(s[i] == '(')
                flag = func(s, n, cnt+1, i+1, dp);
            else{
                if(cnt > 0) flag = func(s, n, cnt-1, i+1, dp);
            }    
        }

        return dp[i][cnt] = flag;
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return func(s, n, 0, 0, dp);
    }
};