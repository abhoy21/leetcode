class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string,int> temp;
        string str;
        for(int i = 0; i < s.length(); i++)
        {
            str = s.substr(i,10);
            temp[str]++;
        }
        for(auto v : temp)
        {
            if(v.second > 1)
                ans.push_back(v.first);
        }
        
        return ans;
        
    }
};