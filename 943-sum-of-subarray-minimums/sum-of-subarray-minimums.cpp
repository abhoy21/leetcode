class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7;
        int n = arr.size();
        vector<int> dp(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            if(st.size() > 0){
                dp[i] = dp[st.top()] + (i-st.top()) * arr[i];
            }
            else{
                dp[i] = (i+1) * arr[i];
            }
            st.push(i);
        }

        int ans = 0;
        for(auto v : dp){
            ans += v;
            ans %= mod;
        }

        return ans;

    }
};