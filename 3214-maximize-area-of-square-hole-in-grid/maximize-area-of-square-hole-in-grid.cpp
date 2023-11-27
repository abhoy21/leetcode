class Solution {
public:
    int func(vector<int>&bars){
        int ans = 2, cnt = 2;
        sort(bars.begin(), bars.end());

        for(int i = 1; i < bars.size(); i++){
            cnt = (bars[i-1]+1 == bars[i]) ? cnt+1:2;
            ans = max(ans, cnt);
        }

        return ans;

    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int gap = min(func(hBars), func(vBars));

        return gap * gap;
    }
};