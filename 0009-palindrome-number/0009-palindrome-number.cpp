class Solution {
public:
    bool isPalindrome(int x) {
        long long ans = 0;
        long y = x;
        while(y > 0)
        {
            int r = y % 10;
            ans = (ans * 10) + r;
            y /= 10;
        }
        return (ans == x);
    }
};