class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0, cnt = 0;
        while(i < s.length() && j < t.length())
        {
            if(s[i] == t[j])
            {
                i++;
                cnt++;
                j++;
            }
            else
            {
                j++;
            }
        }
        
        return cnt == s.length() ? true : false;
        
    }
};