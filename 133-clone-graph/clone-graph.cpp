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
    unordered_map<Node*, Node*> mp;
    Node* DFS(Node* node)
    {
        Node* clone = new Node(node->val);
        vector<Node*> n;
        mp[node] = clone;
        for(auto it: node->neighbors)
        {
            if(mp.find(it) != mp.end())
                n.push_back(mp[it]);
            else
                n.push_back(DFS(it));
        }
        clone->neighbors = n;

        return clone;
        
    }
    Node* cloneGraph(Node* node) {
        
        if(node == nullptr)
            return nullptr;
        if(node->neighbors.size() == 0)
        {
            Node* clone = new Node(node->val);
            return clone;
        }

        return DFS(node);
    }
};