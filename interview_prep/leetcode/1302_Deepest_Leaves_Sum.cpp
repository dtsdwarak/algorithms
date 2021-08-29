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
    
    int maxLevel = INT_MIN;
    int sum = 0;
    
    void fetchDeepestLeavesSum(TreeNode *root, int level) {
        
        if (!root)
            return;
        
        if (level > maxLevel) {
            maxLevel = level;
            sum = root->val;
        }
        else if (level == maxLevel)
            sum += root->val;
        
        fetchDeepestLeavesSum(root->left, level+1);
        fetchDeepestLeavesSum(root->right, level+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        
        fetchDeepestLeavesSum(root, 0);
        return sum;
    }
};
