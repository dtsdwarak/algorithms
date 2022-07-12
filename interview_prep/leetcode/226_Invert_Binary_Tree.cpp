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
    TreeNode* invertTree(TreeNode* root) {
        
        if (!root || (!root->left && !root->right))
            return root;
        
        TreeNode *invertedRight = invertTree(root->right);
        TreeNode *invertedLeft  = invertTree(root->left);
        
        root->right = invertedLeft;
        root->left = invertedRight;
        
        return root;
    }
};
