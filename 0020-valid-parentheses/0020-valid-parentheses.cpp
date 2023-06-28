class Solution {
public:
    bool isopening(char c)
    {
        if(c == '(' || c == '{' || c == '[')
            return true;
        
        return false;
    }
    bool isclosing(char f, char c)
    {
        if(f == '(' && c == ')' || f == '{' && c == '}' || f == '[' && c == ']')
            return true;
        
        return false;
    }
    bool isValid(string s)
    {
        stack<char> ch;
        char curr;
        for(int i = 0; i < s.length(); i++)
        {
            curr = s[i];
            if(isopening(curr))
            {
                ch.push(curr);
            }
            else
            {
                if(ch.empty())
                {
                    return false;
                }
                else if(!isclosing(ch.top(), curr))
                {
                    return false;
                }
                else
                {
                    ch.pop();
                }
            }
        }
        return ch.empty();        
    }
};