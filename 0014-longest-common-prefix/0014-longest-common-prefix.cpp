class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string l = strs[0];
        string r = strs[strs.size() - 1];
        string ans = "";

        for(int i = 0; i < l.length(); i++)
        {
            if(l[i] == r[i])
                ans += l[i];
            else
                break;
        }

        return ans;
    }
};