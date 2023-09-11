class Solution {
public:
    int gcd(int a, int b)
    {
        while(b!=0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1) ? 
        str1.substr(0, gcd(str1.length(), str2.length())) : "";
    }
};