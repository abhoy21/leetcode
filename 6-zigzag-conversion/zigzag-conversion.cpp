class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string ans = "";
        int incr;
        for(int i = 0; i < numRows; i++){
            incr = 2 * (numRows - 1);
            for(int j = i; j < s.length(); j+=incr){
                ans += s[j];
                if(i > 0 && i < numRows - 1 && j + incr - 2 * i < s.length())
                    ans += s[j + incr - 2 * i];
            }
        }

        return ans;
    }
};