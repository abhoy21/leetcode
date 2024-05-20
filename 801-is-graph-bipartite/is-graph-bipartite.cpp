class Solution {
public:
    bool func(vector<vector<int>>& graph, int colors[], int n, int i){
        queue<int> q;
        q.push(i);
        colors[i] = 0;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto adj: graph[curr]){
                if(colors[adj] == -1){
                    colors[adj] = !colors[curr];
                    q.push(adj);
                }
                else if(colors[adj] == colors[curr]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        int colors[n];
        for(int i = 0; i < n; i++)
            colors[i] = -1;
        
        for(int i= 0; i < n; i++){
            if(colors[i] == -1){
                if(func(graph, colors, n, i) == false)
                    return false;
            }
        }

        return true;
    }
};