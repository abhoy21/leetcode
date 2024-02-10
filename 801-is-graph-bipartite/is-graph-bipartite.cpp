class Solution {
public:
    bool bfs(int i, vector<vector<int>> &graph, int color[], int n){
        queue<int> q;
        q.push(i);
        color[i] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto temp : graph[node]){
                if(color[temp] == -1){
                    color[temp] = !color[node];
                    q.push(temp);
                }
                else if(color[temp] == color[node])
                    return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        int color[n];
        for(int i = 0; i < n; i++)
            color[i] = -1;
        
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(bfs(i, graph, color, n) == false)
                    return false;
            }
        }

        return true;
    }
};