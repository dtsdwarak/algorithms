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
    
    int maxDiff;
    
    void computeMaxAncestorDiff(TreeNode* root, int minVal, int maxVal) {
        if (!root)
            return;
        
        maxVal = max(maxVal, root->val);
        minVal = min(minVal, root->val);
        maxDiff = max(maxDiff, abs(maxVal - minVal));
        
        computeMaxAncestorDiff(root->right, minVal, maxVal);
        computeMaxAncestorDiff(root->left, minVal, maxVal);
    }
    
public:
    int maxAncestorDiff(TreeNode* root) {
        
        maxDiff = INT_MIN;
        computeMaxAncestorDiff(root, root->val, root->val);
        return maxDiff;
        
    }
};
