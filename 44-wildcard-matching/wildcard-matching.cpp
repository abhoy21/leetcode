class Solution {
public:
    bool isMatch(string s, string t) {
        int n = t.size();
        int m = s.size();

        vector<bool> prev(m+1, 0), cur(m+1, 0);
        prev[0] = true;
        for(int j = 1; j <= m; j++){
            prev[j] = false;
        }

        for(int i = 1; i<= n; i++){
            bool flag = true;
            for(int ii = 1; ii <= i; ii++){
                if(t[ii-1] != '*'){
                    flag = false;
                    break;
                }
            }
            cur[0] = flag;
            for(int j = 1; j <= m; j++){
                if(t[i-1] == s[j-1] || t[i-1] == '?')
                    cur[j] = prev[j-1];
                else if(t[i-1] == '*')
                    cur[j] = prev[j] || cur[j-1];
                else
                    cur[j] = false;
            }
            prev = cur;
        }

        return prev[m];
    }
};