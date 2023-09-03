class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<char> odd(26,0), even(26.0);

        for(int i = 0; i < s1.length(); i++)
        {
            if(i%2 == 0)
            {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
            else
            {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            }
        }
        for(int i = 0; i < odd.size(); i++)
        {
            if(odd[i] || even[i]) return false;
        }

        return true;
    }
};