class Solution {
private:
    void func(int i, vector<vector<int>>& isConnected, vector<int>& vis,
              int n) {
        vis[i] = 1;
        for (int j = 0; j < n; j++) {
            if (vis[j] == 0 && isConnected[i][j] == 1){
               
                func(j, isConnected, vis, n);
            }
                
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if(vis[i] == 0){
                ans++;
                func(i, isConnected, vis, n);
            }
                
            
        }

        return ans;
    }
};