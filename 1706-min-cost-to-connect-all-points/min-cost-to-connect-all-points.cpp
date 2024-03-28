class DisjointSet{
    vector<int> parent, size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUParent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void findUnionbySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v)
            return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int manhattan_distance(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < points.size(); i++){
            for(int j = i+1; j < points.size(); j++){
                int wt = manhattan_distance(points[i], points[j]);
                edges.push_back({wt, {i, j}});
            }
        }

        sort(edges.begin(), edges.end());
        int mstwt = 0;
        DisjointSet ds(points.size());
        for(auto it: edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if(ds.findUParent(u) != ds.findUParent(v)){
                mstwt += wt;
                ds.findUnionbySize(u, v);
            }
        }


        return mstwt;
    }
};