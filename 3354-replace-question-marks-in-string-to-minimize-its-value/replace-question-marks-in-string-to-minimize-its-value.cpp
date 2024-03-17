class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> freq(26, 0);
        for(auto c: s){
            if(c != '?')
                freq[c - 'a']++;
        }
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '?') continue;
            int minfreq = INT_MAX, minfreqind = 0;
            for(int j = 0; j < 26; j++){
                if(minfreq > freq[j]){
                    minfreq = freq[j];
                    minfreqind = j;
                }
            }    
            temp += ('a' + minfreqind);
            freq[minfreqind]++;
        }
        sort(temp.begin(), temp.end());
        for(int i = 0, j = 0; i < s.size(); i++){
            if(s[i] == '?')
                s[i] = temp[j++];
        }

        return s;
    }
};