class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        vector<int> temp(newInterval.size());
        temp = newInterval;
        int i = 0;
        while(i < intervals.size() && intervals[i][1] < temp[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        while(i < intervals.size() && intervals[i][0] <= temp[1])
        {
            temp[0] = min(temp[0], intervals[i][0]);
            temp[1] = max(temp[1], intervals[i][1]);
            i++;
        }
        ans.push_back(temp);
        while(i < intervals.size())
        {
            ans.push_back(intervals[i]);
            i++;
        }


        return ans;
    }
};