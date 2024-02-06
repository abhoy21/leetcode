class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(auto ch : strs){
            string temp = ch;

            sort(temp.begin(), temp.end());
            mp[temp].push_back(ch);
        }

        for(auto v: mp)
        {
            ans.push_back(v.second);
        }
        
        return ans;
    }
};