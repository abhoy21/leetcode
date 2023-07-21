class Solution {
public:
    int minPartitions(string n) {
        int cnt = 0;
        for(auto v: n)
        {
            if(cnt < v)
                cnt = v;
        }
        return cnt-'0';
    }
};