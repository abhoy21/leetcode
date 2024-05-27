class Solution {
public:
    int count(vector<int>& nums, int mid){
       int cnt = 0;
       for(auto n: nums){
            if(n >= mid)
                cnt++;
       }
       return cnt;
    }

    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int start = 0, end = nums.size();

        while(start <= end){
            int mid = start + (end - start) / 2;

            int cnt = count(nums, mid);

            if(cnt == mid)
                return cnt;
            else if(cnt > mid)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return -1;
    }
};