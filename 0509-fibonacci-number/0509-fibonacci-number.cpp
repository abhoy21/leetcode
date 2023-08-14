class Solution {
public:
    int fib(int n) {
        int a = 0;
        int b = 1;
        
        for(int i = 1; i < n; i++)
        {
            b = a + b;
            a =  b - a;
        }
        
        return n == 0? n: b;
    }
};