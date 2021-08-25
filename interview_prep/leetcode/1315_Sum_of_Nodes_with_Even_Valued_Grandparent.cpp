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
    
    int sumIfEvenGrandParent(TreeNode* root, bool isEvenParent, bool isEvenGrandParent) {
        
        if (!root)
            return 0;
        
        return (isEvenGrandParent ? root->val : 0) 
            + sumIfEvenGrandParent(root->left, !(root->val & 1), isEvenParent)
            + sumIfEvenGrandParent(root->right, !(root->val & 1), isEvenParent);
        
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        return sumIfEvenGrandParent(root, false, false);
    }
};
