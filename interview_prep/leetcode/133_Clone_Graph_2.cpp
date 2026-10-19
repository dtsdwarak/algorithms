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

private:

    vector<Node*> copies;

    Node* dfs(Node* node) {
        
        if (copies[node->val])
            return  copies[node->val];

        Node* clone = new Node(node->val);
        copies[node->val] = clone;
            
        for(auto node_ : node->neighbors) {
            Node* nodeclone_ = dfs(node_);
            clone->neighbors.push_back(nodeclone_);
        }

        return clone;

    }

public:
    Node* cloneGraph(Node* node) {
        
        if (!node)
            return nullptr;

        copies = vector<Node*>(101, nullptr);

        return dfs(node);
    }
};
