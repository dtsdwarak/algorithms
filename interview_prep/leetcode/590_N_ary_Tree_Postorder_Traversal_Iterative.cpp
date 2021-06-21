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
    vector<int> postorder(Node* root) {
        
        stack<Node*> stk1;
        stack<Node*> stk2;
        
        if (root)
            stk1.push(root);
        
        while(!stk1.empty()) {
            
            Node *node = stk1.top();
            stk1.pop();
            
            stk2.push(node);

            for(auto i: node->children)
                stk1.push(i);
            
        }
        
        vector<int> ans;
        while(!stk2.empty()) {
            ans.push_back(stk2.top()->val);
            stk2.pop();
        }
        
        return ans;
        
    }
};
