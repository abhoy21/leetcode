class Solution {
public:
    long long hrsfunc(vector<int> &piles, int h) {
        long long total = 0;
        for(int i = 0; i < piles.size(); i++) {
            int temp = ceil((double)piles[i] / (double)h);
            total += temp;
        }

        return total;
    } 
    int maxele(vector<int> &piles) {
        int maxi = piles[0];
        for(int i = 1; i < piles.size(); i++) {
            if(maxi < piles[i])
                maxi = piles[i];
        }

        return maxi;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = maxele(piles);

        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long hrs = hrsfunc(piles, mid);
            if(hrs <= h) 
                high = mid - 1;
            else
                low = mid + 1; 
        }

        return low;
    }
};