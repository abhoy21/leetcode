class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size());
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < score.size(); i++){
            pq.push({score[i], i});
        }

        vector<string> rank = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        int ind = 1;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int index = temp.second;
            if(ind < 4)
                ans[index] = rank[ind - 1];
            else{
                ans[index] = to_string(ind);
            }
            ind++;
        }

        return ans;
    }
};