class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> ans(deck.size());
        sort(deck.begin(), deck.end());
        queue<int> q;
        for(int i = 0; i < deck.size(); i++)
            q.push(i);

        for(auto n: deck){
            int ind = q.front();
            q.pop();
            ans[ind] = n;
            if(!q.empty()){
                int temp = q.front();
                q.pop();
                q.push(temp);
            }
        }

        return ans;
    }
};