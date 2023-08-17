class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int m = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(vector<int> interval : intervals)
        {
            if(ans.empty())
                ans.push_back(interval);
            
            vector<int> &ptr = ans.back();
            int temp = ptr[1];
            
            if(interval[0] <= temp)
                ptr[1] = max(temp, interval[1]);
            else
                ans.push_back(interval);
                
        }
        
        return ans;
    }
};