class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>mp;
        for(auto i : arr)
            mp[i]++;

        unordered_set<int> cnt;
        for(auto i : mp){
            cnt.insert(i.second);
        }



        return cnt.size() == mp.size() ? true : false;
    }
};