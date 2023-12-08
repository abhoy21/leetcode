class Solution {
public:
    long long hrsfunc(vector<int>& piles, int bhr){
        long long totalhrs = 0;
        for(int i = 0; i < piles.size(); i++){
            int temp = ceil(piles[i] / (double)bhr);
            totalhrs += temp;
        }

        return totalhrs;
    }
    int findMaxElement(vector<int>& piles) {
        int maxElement = piles[0];

        for (int i = 1; i < piles.size(); ++i) {
            if (piles[i] > maxElement) {
                maxElement = piles[i];
            }
        }

        return maxElement;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMaxElement(piles);
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            
            long long hrs = hrsfunc(piles, mid);

            if(hrs <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};