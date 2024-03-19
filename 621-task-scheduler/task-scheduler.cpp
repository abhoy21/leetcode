class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        int ans = 0;
        for(auto ch : tasks){
            mp[ch]++;
        }

        for(auto i: mp){
            pq.push({i.second, i.first});
        }

        while(!pq.empty()){
            if(pq.top().first == 1){
                ans += pq.size();
                break;
            }
            vector<pair<int, char>> v;
            v.push_back(pq.top());
            pq.pop();
            ans += 1;
            for(int i = 0; i < n; i++){
               if(!pq.empty()){
                    v.push_back(pq.top());
                    pq.pop();
               }
                ans++;
            }

            for(auto j: v){
                if(j.first > 1)
                    pq.push({j.first - 1, j.second});
            }
        }

        return ans;
    }
};