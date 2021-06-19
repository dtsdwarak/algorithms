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
    vector<int> preorder(Node* root) {
        
        stack<Node*> s;
        queue<Node*> q;
        
        if (root)
            s.push(root);
        
        while(!s.empty()) {
            
            Node *node = s.top();
            s.pop();
            
            q.push(node);
            
            for(int i=node->children.size()-1; i>-1; i--)
                s.push(node->children[i]);
            
        }
        
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};

