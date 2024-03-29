class Solution {
public:
    int mod = 1e9 + 7;
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> prev(m+1, 0), cur(m+1, 0);
        prev[0] = cur[0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i-1] == t[j-1])
                    cur[j] = (prev[j-1] % mod + prev[j] % mod);
                else
                    cur[j] = prev[j] % mod;
            }
            prev = cur;
        }

        return prev[m];
    }
};