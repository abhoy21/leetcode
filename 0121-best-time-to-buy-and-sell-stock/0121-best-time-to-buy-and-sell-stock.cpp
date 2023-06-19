class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int minsofar = prices[0];
        int maxprofit = INT_MIN;

        for (int i = 0; i < prices.size(); i++)
        {
            if (minsofar > prices[i])
            {
                minsofar = prices[i];
            }
            maxprofit = max(maxprofit, prices[i] - minsofar);
        }

        return maxprofit;
    }
};