class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int minsofar = prices[0], sum =0;
        int maxprofit = 0;

        for (int i = 0; i < prices.size()-1; i++)
        {
            if (prices[i] < prices[i+1])
            {
                minsofar = prices[i];
                maxprofit += prices[i+1] - minsofar;
            }
        }

        return maxprofit;
    }
};