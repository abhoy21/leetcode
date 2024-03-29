class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int Parent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = Parent(parent[node]);
    }

    

    void findUnionbySize(int u, int v) {
        int ul_u = Parent(u);
        int ul_v = Parent(v);
        if (ul_u == ul_v)
            return;
        if (size[ul_u] < size[ul_v]) {
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        } else {
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end())
                    mp[mail] = i;
                else
                    ds.findUnionbySize(i, mp[mail]);
            }
        }

        vector<string> mailMerge[n];

        for(auto it: mp){
            string temp = it.first;
            int node = ds.Parent(it.second);
            mailMerge[node].push_back(temp);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++){
            if(mailMerge[i].size() == 0) continue;
            sort(mailMerge[i].begin(), mailMerge[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto j: mailMerge[i]){
                temp.push_back(j);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};