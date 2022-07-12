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
    
    int diameter = 0;
    
    int fetchMaxLength(TreeNode *root) {
    
        if (!root)
            return 0;
        
        int leftMaxLength = fetchMaxLength(root->left);
        int rightMaxLength = fetchMaxLength(root->right);
        
        int currentDiameter = leftMaxLength + rightMaxLength;
        
        diameter = max(diameter, currentDiameter);
        
        return 1 + max(leftMaxLength, rightMaxLength);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if (!root)
            return 0;
        
        fetchMaxLength(root);
        return diameter;
        
    }
};
