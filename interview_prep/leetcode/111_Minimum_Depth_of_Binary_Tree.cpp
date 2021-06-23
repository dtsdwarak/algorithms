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
    
    int minDepthValue = INT_MAX;
    
    void fetchMinDepth(TreeNode *root, int count) {
        
        if (!root->right && !root->left)
            minDepthValue = min(minDepthValue, count);
        
        if (root->left)
            fetchMinDepth(root->left, count+1);
        if (root->right)
            fetchMinDepth(root->right, count+1);
        
    }
    
    int minDepth(TreeNode* root) {
        
        if (!root)
            return 0;
        
        fetchMinDepth(root, 1);
        
        return minDepthValue;
    }
};
