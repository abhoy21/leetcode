class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<int> adj[N];
        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector<int> indegree(N, 0);
        vector<int> ans;
        queue<int> q;
         for(int i = 0; i < N; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        for(int i = 0; i < N; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        return ans.size() == N ? ans : vector<int>();
    }
};