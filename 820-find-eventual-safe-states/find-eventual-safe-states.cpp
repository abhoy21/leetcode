class Solution {
public:
    bool dfscheck(int node, vector<vector<int>>& adj, vector<int>& vis,
                  vector<int>& pathvis, vector<int>& check) {
        vis[node] = 1;
        pathvis[node] = 1;

        for (int n : adj[node]) {
            if (!vis[n]) {
                if (dfscheck(n, adj, vis, pathvis, check))
                    return true;
            } else if (pathvis[n]) {
                return true;
            }
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        vector<int> check(V, 0);
        vector<int> safeNodes;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfscheck(i, graph, vis, pathvis, check);
            }
        }

        for (int i = 0; i < V; i++) {
            if (check[i] == 1)
                safeNodes.push_back(i);
        }

        return safeNodes;
    }
};