class Solution {
public:
    vector<vector<int>> adj;
    vector<int> v;
    void build_adj(vector<vector<int>>& prerequisites)
    {
        for(vector<int>& x:prerequisites)
        {
            adj[x[1]].push_back(x[0]);
        }
    }
    bool DFS(int i)
    {
        if(v[i] == 1)
            return 0;
        if(v[i] == 2)
            return 1;
        v[i] = 1;
        for(int j: adj[i])
        {
            if(!DFS(j))
                return 0;
        }
        v[i] = 2;
        return 1;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        build_adj(prerequisites);
        v.assign(numCourses, 0);

        for(int i = 0; i < numCourses; i++)
        {
            if(!v[i])
            {
                if(!DFS(i))
                    return 0;
            }
        }
        return 1;
    }
};