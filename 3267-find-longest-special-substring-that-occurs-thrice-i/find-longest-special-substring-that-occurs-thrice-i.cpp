class Solution {
public:
    int maximumLength(string s) {
        map<string, int> mp;
        int cnt = 1;
        string temp = "";
        temp += s[0];
        mp[temp]++;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]){
                cnt++;
                temp += s[i];
            }
            else {
                cnt = 1;
                temp = s[i];
            }

            for(int j = 0; j < temp.size(); j++){
                string sub = temp.substr(0, j+1);
                mp[sub]++;
            }
        }

        int ans = 0;
        for(auto v: mp){
            if(v.second >= 3){
                int size = v.first.size();
                ans = max(ans, size);
            }
        }

        return ans == 0 ? -1 : ans;

    }
};