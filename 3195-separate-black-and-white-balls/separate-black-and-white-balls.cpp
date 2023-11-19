class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0LL;
        int ones = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1')
                ones++;
            else
                ans += ones;
        }


        return ans;
    }
};