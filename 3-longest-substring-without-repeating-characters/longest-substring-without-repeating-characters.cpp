class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0, j = 0, maxlen = 0;
        map<char, int> mp;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
            len++;
            while(mp[s[i]] > 1){
                mp[s[j]]--;
                j++;
                len--;
            }
            maxlen = max(len, maxlen);
        }

        return maxlen;
    }
};