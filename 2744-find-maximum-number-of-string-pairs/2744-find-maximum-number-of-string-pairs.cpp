class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int cnt = 0;
        set<string> str;
        for(auto v : words)
        {
            sort(v.begin(), v.end());
            if(str.count(v) != 0)
                cnt++;
            else
                str.insert(v);
        }
        
        return cnt;
        
    }
};