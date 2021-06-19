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
    TreeNode* increasingBST(TreeNode* root) {
        
        if (!root)
            return nullptr;
        
        if (!root->left && !root->right)
            return root;
        
        TreeNode *left = increasingBST(root->left);
        
        if (left) {  
            TreeNode *node = left;
            while(node->right)
                node = node->right;
            node->right = root;
            root->left = nullptr;
        }
        else
            left = root;
        
        root->right = increasingBST(root->right);
        return left;
        
    }
};

