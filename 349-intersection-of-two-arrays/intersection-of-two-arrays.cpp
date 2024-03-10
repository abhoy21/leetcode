class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for(auto n: nums2){
            if(m.count(n)){
                res.push_back(n);
                m.erase(n);
            }
        }

        return res;
    }
};