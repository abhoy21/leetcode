class Solution {
public:
    double exponent(double x, int n)
    {
        if(n == 0)
            return 1;
        double temp = exponent(x,n/2);
        if(n%2 != 0)
            return temp * temp * x;
         return temp * temp; 
    }
    double myPow(double x, int n) {
        if(n < 0)
            return (1 / exponent(x,abs(n)));
        return exponent(x,n);
    }
};