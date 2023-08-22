class Solution {
public:
    char tolowercase(char ch)
    {
        return (ch >= 'A' && ch <= 'Z') ? ch + ('a' - 'A') : ch;
    }
    bool isPalindrome(string s) {
        string ans;
        for(char ch: s)
        {
            if(isalnum(ch))
                ans += ch;
        }
        int l = 0;
        int r = ans.length() - 1;
        
        while(l<r)
        {
            if(tolowercase(ans[l]) != tolowercase(ans[r]))
                return 0;
            l++;
            r--;
        }
        
        return 1;
    }
};