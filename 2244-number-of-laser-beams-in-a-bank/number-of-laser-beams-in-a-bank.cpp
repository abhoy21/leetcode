class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ans = 0;

        for(string s: bank) {
            int cur = 0;
            for(char c: s) {
                if(c == '1')
                    cur++;
            }
            if(cur != 0) {
                ans += prev * cur;
                prev = cur;
            }
        }

        return ans;
    }
};