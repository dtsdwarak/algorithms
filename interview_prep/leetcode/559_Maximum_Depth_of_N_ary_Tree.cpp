/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    int maxDepthValue = 0;
    
    void FindMaxDepth(Node* root, int depth) {
        
        if (!root)
            return;
        
        depth++;
        
        if (root->children.size() == 0) {
            maxDepthValue = max(maxDepthValue, depth);
            return;
        }
        
        for(Node *i : root->children)
            FindMaxDepth(i, depth);
    }
    
    int maxDepth(Node* root) {
        FindMaxDepth(root, 0);
        return maxDepthValue;
    }
};
