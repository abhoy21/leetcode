class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q{{1,2,3,4,5,6,7,8,9}};

        while(!q.empty()){
            int nums = q.front();
            q.pop();
            if(nums > high)
                return ans;
            if(low <= nums && nums <= high)
                ans.push_back(nums);
            int lastd = nums % 10;
            if(lastd < 9)
                q.push(nums * 10 + lastd + 1);
        }

        return ans;
    }
};