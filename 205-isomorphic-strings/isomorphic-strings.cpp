class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, char> mps;
        unordered_map<char, char> mpt;
        
        for(int i = 0; i < s.size(); i++){
            if(mps[s[i]] && mps[s[i]] != t[i]) return false;
            if(mpt[t[i]] && mpt[t[i]] != s[i]) return false;

            mpt[t[i]] = s[i];
            mps[s[i]] = t[i];
        }

        return true;
    }
};