class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minsofar = prices[0];
        int maxprofit = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(minsofar > prices[i])
            {
                minsofar = prices[i];
            }
            maxprofit = max(maxprofit, prices[i]-minsofar);
        }
        
        return maxprofit;
    }
};