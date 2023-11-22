class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_freq(26, 0), s2_freq(26, 0);
        int s1_len = s1.size(), s2_len = s2.size();
        
        if (s1_len > s2_len) return false;
        
        for (int i = 0; i < s1_len; i++) {
            s1_freq[s1[i] - 'a']++;
            s2_freq[s2[i] - 'a']++;
        }
        
        for (int i = s1_len; i < s2_len; i++) {
            if (s1_freq == s2_freq) return true;
            
            s2_freq[s2[i] - 'a']++;
            s2_freq[s2[i - s1_len] - 'a']--;
        }
        
        return s1_freq == s2_freq;
    }
};
