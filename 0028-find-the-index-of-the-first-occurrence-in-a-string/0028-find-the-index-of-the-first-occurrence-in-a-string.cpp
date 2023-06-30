class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i < haystack.length(); i++)
        {
            if(needle == haystack.substr(i, needle.length()))
            {
                return i;
                break;
            }
        }
        return -1;
    }
};