class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], maxprofit = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(mini > prices[i])
                mini = prices[i];
            maxprofit = max(maxprofit, prices[i] - mini);
        }

        return maxprofit;
    }
};