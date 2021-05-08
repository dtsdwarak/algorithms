/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void parseLeftTree(TreeNode* root, stack<TreeNode*> &s) {
        
        while(root->left) {
            if (root->right)
                s.push(root->right);
            s.push(root);
            root = root->left;
        }
        
        if (root->right)
            s.push(root->right);
        s.push(root);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        if (!root)
            return vector<int>();
        
        stack<TreeNode*> s;
        vector<int> ans;
        
        parseLeftTree(root, s);
        
        while(!s.empty()) {
            
            root = s.top();
            s.pop();
            
            if (!s.empty() && root->right == s.top()) {
                TreeNode *temp = s.top();
                s.pop();
                s.push(root);
                root = temp;
                parseLeftTree(root, s);
            } else 
                ans.push_back(root->val);
            
        }
        
        return ans;
        
    }
};
