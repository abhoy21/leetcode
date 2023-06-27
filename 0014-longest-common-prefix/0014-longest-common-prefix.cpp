class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string l = strs.front();
        string r = strs.back();
        string sub;
        for(int i = 0; i<l.length(); i++)
            if(l[i] == r[i])
                sub+= l[i];
            else
                break;
        
        
        
        return sub;
    }
};