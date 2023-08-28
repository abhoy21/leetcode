class Solution {
public:

    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int i = 32;
        while(i--)
        {
            uint32_t e = n&1;
            ans <<= 1;
            ans |= e;
            n>>=1;
        }

        return ans;
    }
};