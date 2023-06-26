class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        string str;
        int cnt = 0;
        for(int i = 0; i < num.length(); i++)
        {
            if(num[i]-48 < change[num[i] - 48])
            {
                num[i] = change[num[i] - 48] + 48;
                cnt = 1;
            }
            else if(cnt == 1 && num[i] - 48 > change[num[i] - 48])
            {
                break;
            }

                
        }
        
        return num;
        
    }
};