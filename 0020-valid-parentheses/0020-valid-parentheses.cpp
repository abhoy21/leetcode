class Solution {
public:
    bool isopening(char ch)
    {
        if(ch == '(' || ch == '{' || ch == '[')
            return true;
        return false;
    }
    bool isclosing(char ch1, char ch2)
    {
        if(ch1 == '(' && ch2 == ')' || ch1 == '{' && ch2 == '}' || ch1 == '[' && ch2 == ']')
            return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(isopening(s[i]))
                st.push(s[i]);
            else
            {
                if(st.empty())
                    return false;
                else if(!isclosing(st.top(), s[i]))
                    return false;
                else
                    st.pop();
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};