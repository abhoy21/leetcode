class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minsofar = prices[0], maxprofit = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < minsofar)
                minsofar = prices[i];
            maxprofit = max(maxprofit, prices[i] - minsofar);
        }

        return maxprofit;
    }
};