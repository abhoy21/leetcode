class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int c1 = 0;
        
        for(int i = 0; i<s.length();i++)
        {
            if(s[i] == '(')
            {
                c1++;
            }
            else if (s[i] == ')')
            {
                if(c1==0)
                {
                    s[i] = '#';
                }
                else
                    c1--;
            }
        }
        
        int c2 = 0;
        
        for(int i = s.length() - 1; i>=0;i--)
        {
            if(s[i] == ')')
            {
                c2++;
            }
            else if (s[i] == '(')
            {
                if(c2==0)
                {
                    s[i] = '#';
                }
                else
                    c2--;
            }

        }
        
        string ans;
        
        for(int i = 0; i< s.length();i++)
        {
            if(s[i] != '#')
                ans.push_back(s[i]);
        }
        
        return ans;
    }
};