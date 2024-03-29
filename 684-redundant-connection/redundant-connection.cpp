class DisjointSet{
  public:
  vector<int> parent, size;
  DisjointSet(int n){
      parent.resize(n+1);
      size.resize(n+1);
      for(int i = 0; i < n; i++){
          parent[i] = i;
          size[i] = 1;
      }
  }
  int Parent(int node){
      if(node == parent[node])
        return node;
      return parent[node] = Parent(parent[node]);    
  }
  void findUnion(int u, int v){
      int ulpu = Parent(u);
      int ulpv = Parent(v);
      if(ulpu == ulpv) return;
      if(size[ulpu] < size[ulpv]){
          parent[ulpu] = ulpv;
          size[ulpv] += size[ulpu];
      }
      else{
          parent[ulpv] = ulpu;
          size[ulpu] += size[ulpv];
      }
  }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        DisjointSet ds(edges.size());
        for(auto it: edges){
            int u = it[0];
            int v = it[1];

            if(ds.Parent(u) == ds.Parent(v))
                return {u, v};
            else
                ds.findUnion(u,v);
        }

        return {};
    }
};