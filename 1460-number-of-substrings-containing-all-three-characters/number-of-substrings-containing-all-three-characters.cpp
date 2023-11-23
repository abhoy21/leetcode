class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int i = 0, j = 0, cnt = 0;
        unordered_map<char, int>mp;

        while(j < n){
            mp[s[j]]++;
            while(mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1){
                cnt += n - j;

                mp[s[i]]--;
                i++;
            }
            j++;
        }

        return cnt;
    }
};