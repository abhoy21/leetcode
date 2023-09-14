class Solution {
public:
    void func(vector<string> & ans, int n, int open, int close, string curr_str)
    {
        if(curr_str.length() == n*2)
        {
            ans.push_back(curr_str);
            return;
        }

        if(open < n)
            func(ans, n, open+1, close, curr_str+"(");
        if(close < open)
            func(ans, n, open, close+1, curr_str+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func(ans, n, 0, 0, "");

        return ans;
    }
};