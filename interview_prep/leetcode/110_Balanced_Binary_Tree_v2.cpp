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
    
    int getHeight(TreeNode *root) {
        
        if (!root)
            return 0;
        
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        if (leftHeight == INT_MAX || rightHeight == INT_MAX || abs(leftHeight-rightHeight) > 1)
            return INT_MAX;
        
        return 1 + max(leftHeight, rightHeight);;
    }
    
    
public:
    bool isBalanced(TreeNode* root) {
        
        if (!root)
            return true;
        
        return (getHeight(root) != INT_MAX);
        
    }
};
