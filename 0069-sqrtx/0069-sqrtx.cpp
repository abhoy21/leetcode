class Solution {
public:
    int mySqrt(int x) {
        long long l = 0;
        long long r = x;
        
        while(l<=r)
        {
            long long mid = l + (r-l)/2;
            
            if((mid * mid) == x)
            {
                return mid;
            }
            
            else if((mid * mid) > x)
            {
                r = mid - 1;
            }
                
            else
            {
                l = mid + 1;
            }
                
        }
        
        return r;
    }
};