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
    
    vector<int> fetchLeaves(TreeNode *root) {
        
        vector<int> ans;
        
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()) {
            
            TreeNode *node = s.top();
            s.pop();
            
            if (!node->left && !node->right)
                ans.push_back(node->val);
             
            if (node->left)
                s.push(node->left);
            if (node->right)
                s.push(node->right);
        }
        
        return ans;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return fetchLeaves(root1) == fetchLeaves(root2);
    }
};
