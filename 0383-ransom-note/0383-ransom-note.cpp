class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>mp;
        for(char ch: magazine)
        {
            mp[ch]++;
        }
        for(char ch: ransomNote)
        {
            if(mp.find(ch)!=mp.end())
            {
                if(mp[ch]>0)
                    mp[ch]--;
                else
                    return false;
            }
            else
                return false;
        }
        
        return true;
    }
};