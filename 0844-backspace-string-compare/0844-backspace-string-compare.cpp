class Solution {
public:
    stack<char> stck;
    void backspace(string& str)
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == '#')
            {
                if(!stck.empty())
                    stck.pop();
                else
                    continue;
            }
            else
                stck.push(str[i]);
        }
        str = "";
        while(!stck.empty())
        {
            str += stck.top();
            stck.pop();
        }
    }
    bool backspaceCompare(string s, string t) {
        backspace(s);
        backspace(t);
        return s == t ? true : false;
    }
};