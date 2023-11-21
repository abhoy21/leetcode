class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, i = 0, j = 0, maxi = 0;
        unordered_map<char, int> mp;

        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
            maxi = max(maxi, mp[s[i]]);
            if(i-j+1-maxi > k){
                mp[s[j]]--;
                j++;
            }
            ans = max(ans, i-j+1);
        }

        return ans;
        
    }
};