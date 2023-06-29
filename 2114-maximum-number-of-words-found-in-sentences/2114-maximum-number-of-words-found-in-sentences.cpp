class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int cnt=0, maxcnt=0;
        for(auto i : sentences)
        {
            cnt = 0;
            for(auto j : i)
            {
                if(j == ' ')
                {
                    cnt++;
                }

            }
     
            maxcnt = max(cnt, maxcnt);
        }
        
        return maxcnt+1;
    }
};