class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>>pq;
        pq.push({1,start_node}); 
        vector<double> prob(n, 0);
        prob[start_node] = 1;
        
        while(!pq.empty()){
            auto it = pq.top();
            double probability = it.first;
            int node = it.second;
            pq.pop();
            for(auto i: adj[node]){
                double adjprob = i.second;
                int adjnode = i.first;

                if(probability * adjprob > prob[adjnode]){
                    
                    prob[adjnode] = probability * adjprob;
                    pq.push({prob[adjnode], adjnode});
                }
            }
        }

        return prob[end_node];
    }
};