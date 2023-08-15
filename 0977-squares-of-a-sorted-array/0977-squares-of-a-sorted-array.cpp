

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=nums.size()-1, k=nums.size()-1;
        vector<int>v(nums.size(),0);
        while(i<=j)
        {
            if(abs(nums[i])>=abs(nums[j]))
             v[k--]=(pow(nums[i++],2));
            
            else v[k--]=(pow(nums[j--],2));
        }
        return v;
    }
};

