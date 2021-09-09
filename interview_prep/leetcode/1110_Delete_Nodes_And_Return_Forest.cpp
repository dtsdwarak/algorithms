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
    
    TreeNode* treePruning(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>& results) {
        
        if (!root)
            return nullptr;
        
        root->left = treePruning(root->left, to_delete, results);
        root->right = treePruning(root->right, to_delete, results);
        
        if (find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()) {
            
            if (root->left)
                results.push_back(root->left);
            
            if (root->right)
                results.push_back(root->right);
                
            return nullptr;
        }
        
        return root;
    }
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        
        vector<TreeNode*> results;
        if (treePruning(root, to_delete, results))
            results.push_back(root);
        
        return results;
        
    }
};
