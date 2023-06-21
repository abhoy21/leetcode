class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int i = 0, j=0;
        vector<int> neg;
        vector<int> pos;
        for(int i=0; i<nums.size();i++){
            if(nums[i]>=0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        vector<int> ans;
        while(i<pos.size() && j<neg.size())
        {
            ans.push_back(pos[i]);
            ans.push_back(neg[j]);
            i++;
            j++;
        }  
        
        return ans;
    }
};