class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mp;
        for(auto match: matches) {
            if(mp.find(match[0]) == mp.end())
                mp[match[0]] = 0;
            mp[match[1]]++;
        }
        vector<int> one, zero;

        for(auto m: mp){
            if(m.second == 0)
                zero.push_back(m.first);
            else if(m.second == 1)
                one.push_back(m.first);
        }

        vector<vector<int>> ans;
        ans.push_back(zero);
        ans.push_back(one);

        return ans;
    }
};