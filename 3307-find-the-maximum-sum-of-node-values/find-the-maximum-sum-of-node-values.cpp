class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long total = 0;
        int cnt = 0;
        int pos = INT_MAX, neg = INT_MIN;

        for(int val: nums){
            int opval = val ^ k;
            int net = opval - val;
            total += val;

            if(net > 0){
                pos = min(pos, net);
                cnt++;
                total += net;
            }
            else{
                neg = max(neg, net);
            }
        }

        if(cnt % 2 == 0)
            return total;
        
        return max(total- pos, total + neg);
    }
};