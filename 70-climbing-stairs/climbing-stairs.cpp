class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, prev2 = 0;
        for(int i = 0; i < n; i++) {
            int cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }

        return prev;
    }
};