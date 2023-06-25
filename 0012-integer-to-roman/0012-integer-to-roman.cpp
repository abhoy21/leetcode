class Solution {
public:
    string intToRoman(int num) {
        string str;
        std::vector<int> nums = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        std::vector<string> ch = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};


        int i = nums.size()-1;
        while(num > 0)
        {
            if(nums[i] <= num)
            {
                num = num - nums[i];
                str += (ch[i]);
            }
            else
            {
                i--;
            }
        }
                
        return str;

    }
};