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
        
        if (!root)
            return vector<int>();
        
        vector<int> ans = {root->val};
        
        for(auto i: root->children) {
            vector<int> iValue = preorder(i);
            ans.insert(ans.end(), iValue.begin(), iValue.end());
        }
        
        return ans;
        
    }
};

