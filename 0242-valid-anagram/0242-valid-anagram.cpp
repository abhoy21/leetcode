class Solution {
public:
    bool isAnagram(string s, string t) {
        bool flag = 0;
        vector<int> freq(26, 0);
        if (s.length() != t.length()) {
            return false;
        }
        for(int i = 0;i<s.length();i++)
        {
            freq[s[i]- 'a']++;
            freq[t[i] - 'a']--;
        }
        for(int i = 0; i< freq.size(); i++ )
        {
            if(freq[i] != 0)
            {
                 return 0;
                break;
            }
               

        }
        return 1;
    }
};