class Solution {
public:
    int pivotInteger(int n) {
        double ans = sqrt(n * (n+1) / 2.0);
        
        if(ans - ceil(ans) != 0.0)
            return -1;
        return (int)(ans);
    }
};