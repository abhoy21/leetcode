class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1000000007;
        vector<vector<int>> dp_last(2, vector<int>(3, 0)); 
        vector<vector<int>> dp_current(2, vector<int>(3, 0)); 

        dp_last[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int count_a = 0; count_a < 2; count_a++) {
                for (int count_l = 0; count_l < 3; count_l++) {

                    dp_current[count_a][0] = (dp_current[count_a][0] + dp_last[count_a][count_l]) % MOD;

                    if (count_a == 0) {
                        dp_current[count_a + 1][0] = (dp_current[count_a + 1][0] + dp_last[count_a][count_l]) % MOD;
                    }

                    if (count_l < 2) {
                        dp_current[count_a][count_l + 1] = (dp_current[count_a][count_l + 1] + dp_last[count_a][count_l]) % MOD;
                    }
                }
            }
            dp_last = dp_current; 
            dp_current = vector<vector<int>>(2, vector<int>(3, 0)); 
        }
        
        int res = 0;
        for (int count_a = 0; count_a < 2; count_a++) {
            for (int count_l = 0; count_l < 3; count_l++) {
                res = (res + dp_last[count_a][count_l]) % MOD;
            }
        }
        return res;
    }
};