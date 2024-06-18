class Solution {
public:
    int binarySearch(vector<pair<int, int>>& list, int target) {
        int left = 0, right = list.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list[mid].first <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> temp;
        for(int i= 0; i < difficulty.size(); i++){
            temp.push_back({difficulty[i], profit[i]});
        }

        sort(temp.begin(), temp.end());

        vector<pair<int, int>> cal;
        int maxi = 0;
        for(auto i: temp){
            int d = i.first;
            int p = i.second;
            maxi = max(maxi, p);
            cal.push_back({d, maxi});
        }

        int ans = 0;
        for(auto w: worker){
            int ind = binarySearch(cal, w);
            if(ind >= 0 && w >= cal[ind].first){
                ans += cal[ind].second;
            }
        }

        return ans;
    }
};