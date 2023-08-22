class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(52,0);
        for (char c : s) {
            if (c >= 'a' && c <= 'z')
                freq[c - 'a']++;
            else if (c >= 'A' && c <= 'Z')
                freq[c - 'A' + 26]++;
        }

        int sum = 0;
        bool flag = false;
        for(int i = 0; i < freq.size(); i++)
        {
            if(freq[i] % 2 == 0)
                sum += freq[i];
            else
            {
                sum += freq[i] - 1;
                flag = true;
            }
        }

        return flag ? sum + 1 : sum;
    }
};