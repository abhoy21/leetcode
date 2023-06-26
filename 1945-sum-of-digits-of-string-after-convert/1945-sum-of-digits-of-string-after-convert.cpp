class Solution {
public:
    int getLucky(string s, int k) {
       int ans=0;
            for(auto i:s){
                int num=i-96;
                if(num < 10)
                {
                    ans += num;
                }
                else
                {
                    ans=ans+(num%10);
                    num/=10;
                    ans += num;
                }
            }
        if(k==1)
        {
            return ans;
        }
        else
        {
            for(int j=0;j<k-1;j++)
            {
                int temp=0;
                while(ans)
                {
                    temp += ans%10;
                    ans/=10;
                }
                ans=temp;
            }
           
        }
             return ans;
        
    }
};