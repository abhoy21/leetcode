class Solution
{
    int minimum(int a, int b)
    {
        if (a < b)
            return a;
        
        return b;
    }

public:
    int trap(vector<int> &a)
    {
        vector<int> prefix(a.size(), 0);
        vector<int> suffix(a.size(), 0);
        int prefixmax = INT_MIN;
        int suffixmax = INT_MIN;
        int temp, water = 0;

        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] > prefixmax)
            {
                prefixmax = a[i];
            }
            prefix[i] = prefixmax;
        }
        for (int i = a.size() - 1; i >= 0; i--)
        {
            if (a[i] > suffixmax)
            {
                suffixmax = a[i];
            }
            suffix[i] = suffixmax;
        }
        for (int i = 0; i < a.size(); i++)
        {
            temp = minimum(suffix[i], prefix[i]) - a[i];
            water += temp;
        }

        return water;
    }
};