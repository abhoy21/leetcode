class Solution {
public:
    int longestAlternatingSubarray(vector<int>& n, int threshold) {
    int res = 0;
    for (int l = 0, cnt = 0; l < n.size(); ++l) {
        if (n[l] <= threshold) {
            if (cnt != 0)
                cnt = n[l] % 2 == n[l - 1] % 2 ? 0 : cnt + 1;
            if (cnt == 0)
                cnt = n[l] % 2 == 0;
        }
        else
            cnt = 0;
        res = max(res, cnt);
    }
    return res;

        
    }
};