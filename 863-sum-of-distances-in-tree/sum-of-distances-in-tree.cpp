class Solution {
public:
    vector<vector<int>> graph;
    vector<int> count;
    vector<int> ans;
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        count.assign(n, 1);
        ans.assign(n, 0);
        
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        dfs(0, -1);
        dfs2(0, -1);
        
        return ans;
    }
    
    void dfs(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                dfs(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }
    
    void dfs2(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                ans[child] = ans[node] - count[child] + graph.size() - count[child];
                dfs2(child, node);
            }
        }
    }
};