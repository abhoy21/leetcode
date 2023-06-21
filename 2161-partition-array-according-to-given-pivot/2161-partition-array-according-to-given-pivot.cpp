class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int low=0, same=0, high;
        for(auto v: nums){
            if(v < pivot)
                low++;
            else if(v == pivot)
                same++;
        }
        vector<int> ans(nums.size());
        high = low + same;
        same = low;
        low = 0;
        for(auto v: nums){
            if(v < pivot)
                ans[low++] = v; 
            else if(v == pivot)
                ans[same++] = v;
            else
                ans[high++] = v;
        }
        
        return ans;
    }
    
        
};
