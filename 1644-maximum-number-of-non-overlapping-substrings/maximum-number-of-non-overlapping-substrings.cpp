class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<string> ans;
        vector<int> start(26, -1);
        vector<int> end(26, 0);
        vector<int> skip(26, 0);
        int cut = INT_MAX;
        for(int i = 0; i < s.size(); i++){
            int idx = s[i] -'a';
            if(start[idx] == -1)
                start[idx] = i;
            end[idx] = i;
        }

        for(int i = 0; i < 26; i++){
            if(start[i] == -1)
                continue;
            for(int j = start[i]; j <= end[i]; j++){
                if(start[s[j] - 'a'] < start[i]){
                    skip[i] = 1;
                    break;
                }

                else
                    end[i] = max(end[i], end[s[j] - 'a']);
            }
        }

        for(int i = s.size() - 1; i >= 0; i--){
            if(i == start[s[i] - 'a'] && end[s[i] - 'a'] < cut && !skip[s[i] - 'a']){
                ans.push_back(s.substr(i, end[s[i] - 'a'] - i + 1));
                cut = i;
            }
        }

        return ans;
    }
};