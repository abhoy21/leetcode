class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        vector<int>v(temperatures.size(), 0);

        for(int i = temperatures.size() - 1; i >= 0; i--){
            while(stk.size() > 0 && stk.top().first <= temperatures[i]){
                stk.pop();
            }

            if(!stk.empty())
                v[i] = stk.top().second - i;
            
            stk.push({temperatures[i], i});
        }

        return v;
    }
};