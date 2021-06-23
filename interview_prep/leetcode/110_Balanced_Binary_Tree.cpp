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
    
    int getHeight(TreeNode *root) {
        
        if (!root)
            return 0;
        
        return 1 + max(getHeight(root->left), getHeight(root->right));
        
    }
    
    bool isBalanced(TreeNode *root) {
        
        if (!root || (!root->left && !root->right))
            return true;
        
        // Remember, just checking the height difference wont' suffice. It must also be checked for balanced in the child trees.
        // e.g. tree - "[1,2,2,3,null,null,3,4,null,null,4]"
        // image - https://ibb.co/2gXDTsF
        if (abs(getHeight(root->left) - getHeight(root->right)) > 1 || !isBalanced(root->left) || !isBalanced(root->right))
            return false;
        
        return true;
    }
};
