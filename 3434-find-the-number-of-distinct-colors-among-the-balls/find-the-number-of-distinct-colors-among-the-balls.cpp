class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballcnt;
        unordered_map<int, int> colorcnt;
        set<int> st;
        vector<int> ans;

        for(auto q: queries){
            int ball = q[0];
            int color = q[1];

            if(ballcnt.count(ball) > 0){
                int old = ballcnt[ball];
                colorcnt[old]--;

                 if(colorcnt[old] == 0)
                    st.erase(old);
            }
               
            ballcnt[ball] = color;
            colorcnt[color]++;

            st.insert(color);
            ans.push_back(st.size());
        }

        return ans;
    }
};