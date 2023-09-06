class Solution {
public:
    int myAtoi(string s) {
        double ans = 0;
        int i = 0;
        while(s[i] == ' ')
        {
            i++;
        }

        int positive = 0, negative = 0; 
        if(s[i] == '+')
        {
            positive++;
            i++;
        }
        if(s[i] == '-')
        {
            negative++;
            i++;
        }
        while(i < s.length() && s[i] >= '0' && s[i] <= '9')
        {
            ans = ans * 10 +  s[i] - '0';
            i++;
        }
        if(negative > 0)
            ans = -ans;
        if(positive > 0 && negative > 0)
            return 0;
        if(ans > INT_MAX)
            ans = INT_MAX;

        if(ans < INT_MIN)
            ans = INT_MIN;

        return int(ans);
    }
};