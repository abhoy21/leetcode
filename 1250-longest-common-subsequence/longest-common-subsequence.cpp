class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
       int n1 = text1.size();
       int n2 = text2.size();

       vector<int> prev(n2+1, 0), cur(n2+1, 0);

       for(int i = 1; i <= n1; i++) {
           for(int j = 1; j <= n2; j++) {
                if(text1[i-1] == text2[j-1])
                    cur[j] = 1 + prev[j-1];
                else
                    cur[j] = max(prev[j], cur[j-1]);
            }
           prev = cur;
        }

        return prev[n2]; 
    }
};