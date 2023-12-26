class Solution {
public:
    int climbStairs(int n) {
       int ans, one = 1, two = 0;

       for(int i = n-1; i >= 0; i--){
           ans = one + two;
           two = one;
           one = ans;
       }

       return one;
    }
};