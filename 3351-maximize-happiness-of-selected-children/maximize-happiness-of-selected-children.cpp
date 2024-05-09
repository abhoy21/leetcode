class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int n =happiness.size();
        long c = 0, ans = 0;
        int i = n - 1;
        while(k--){
            if(happiness[i] - c < 0)
                return ans;
            ans += (long)happiness[i] - c;

            i--;
            c++;
        }
        return ans;
    }
};