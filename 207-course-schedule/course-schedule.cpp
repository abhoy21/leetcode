class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> topo;
        vector<int> indegree(numCourses, 0);
        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            for(auto it: adj[i])
                indegree[it]++;
        }

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int temp = q.front();
            q.pop();
            topo.push_back(temp);
            for(auto it: adj[temp]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        return topo.size() == numCourses;
    }
};