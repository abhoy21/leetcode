class Solution {
public:
    string removeStars(string s) {
        string str = "";
        vector<char> ch(s.size());
        int j = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '*')
                j--;
            else
                ch[j++] = s[i];
        }
        
        for(int i = 0; i < j; i++)
        {
            str += ch[i];
        }
        
        return str;
    }
};