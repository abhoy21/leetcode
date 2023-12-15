class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1);
        dp[0] = 1;
        if(s[0] == '0') dp[1] = 0;
        else dp[1] = 1;
        for(int i = 2; i <= s.size(); i++){
            int w1, w2;
            if(s[i-1] == '0')
                w1 = 0;
            else 
                w1 = dp[i-1];
            if(stoi(s.substr(i-2,2))<=26&&stoi(s.substr(i-2,2))>0&&s[i-2]!='0')
                w2 = dp[i-2];
            else 
                w2 = 0;
            dp[i] = w1 + w2;
        }

        return dp[s.size()];
    }
};