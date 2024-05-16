/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;

        Node* ans = new Node(node->val, {});
        mp[node] = ans;
        q.push(node);

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();

            for(Node* adj: cur->neighbors){
                if(mp.find(adj) == mp.end()){
                    mp[adj] = new Node(adj->val, {});
                    q.push(adj);
                }

                mp[cur]->neighbors.push_back(mp[adj]);
            }
        }

        return ans;
    }
};