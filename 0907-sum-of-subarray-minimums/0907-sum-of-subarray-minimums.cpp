class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> dp(arr.size());
        stack<int> s;
        int MOD = 1000000007;
       for(int i = 0; i < arr.size();i++)
       {
           while(!s.empty() && arr[s.top()]>arr[i])
           {
               s.pop();
           }
           if(s.size() > 0){
               int prevsmall = s.top();
               dp[i] = dp[prevsmall] + (i-prevsmall)* arr[i];
           }
           else
           {
               dp[i] = (i+1) * arr[i];
           }
           
           s.push(i);
       }
        
        int sumofmin = 0;
        for(int cnt : dp)
        {
            sumofmin += cnt;
            sumofmin %= MOD;
        }
        
        return sumofmin;
    }
};