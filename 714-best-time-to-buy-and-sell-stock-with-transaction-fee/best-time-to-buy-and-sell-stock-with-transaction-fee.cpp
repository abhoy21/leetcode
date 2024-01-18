class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> prev(2, 0), cur(2, 0);

        for(int i = n-1; i >= 0; i--){
            cur[1] = max(-prices[i] + prev[0], 0 + prev[1]);
            cur[0] = max(prices[i] - fee + prev[1], 0 + prev[0]);

            prev = cur;
        }

        return prev[1];
    }
};