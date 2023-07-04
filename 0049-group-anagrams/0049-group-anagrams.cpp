class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> anagram;
        vector<vector<string>> ans;
        for(auto v: strs)
          {
              string str = v;
              sort(str.begin(), str.end());
              
              anagram[str].push_back(v);
          }
        
        for(auto v: anagram)
        {
            ans.push_back(v.second);
        }
        
        return ans;
    }
};