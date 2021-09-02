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

    int count=0;
    
    void goodNodes(TreeNode* root, int maxValue) {
        
        if (!root)
            return;
                    
        if (root->val >= maxValue)
            count++;
        
        maxValue = max(maxValue, root->val);
        goodNodes(root->left, maxValue);
        goodNodes(root->right, maxValue);
    }
    
public:
    
    int goodNodes(TreeNode* root) {
        
        goodNodes(root, INT_MIN);
        return count;
    }
};
