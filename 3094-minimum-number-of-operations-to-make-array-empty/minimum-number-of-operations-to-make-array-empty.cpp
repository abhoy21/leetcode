class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> mp;
        for(int n : nums) 
            mp[n]++;
        for(auto v : mp) {
            if(v.second == 1)
                return -1;
            count += v.second / 3 + (v.second % 3 > 0);
        }

        return count;
    }
};