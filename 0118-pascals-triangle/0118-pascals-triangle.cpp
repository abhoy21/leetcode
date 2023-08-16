class Solution {
public:

    vector<int> pascal(int r)
    {
        vector<int> ans;
        ans.push_back(1);
        int curr = 1;
        for(int i = 1;i<r;i++)
        {
            curr*=(r-i);
            curr/=i;
            ans.push_back(curr);
        }
        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1;i<=numRows;i++)
        {
            ans.push_back(pascal(i));
        }

        return ans;
    }
};