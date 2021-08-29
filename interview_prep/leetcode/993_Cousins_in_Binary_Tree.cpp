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
    
    pair<TreeNode*,int> findDetail(TreeNode *node, int val, int height) {
        
        if (!node)
            return make_pair(nullptr, height+1);
        
        if ((node->left && node->left->val == val) || (node->right && node->right->val == val))
            return make_pair(node,height+1);
        
        
        pair<TreeNode*,int> leftParse = findDetail(node->left, val, height+1);
        if (leftParse.first)
            return leftParse; 
        return findDetail(node->right, val, height+1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        if (root->val == x || root->val == y)
            return false;
        
        pair<TreeNode*, int> xParse = findDetail(root, x, 0);
        pair<TreeNode*, int> yParse = findDetail(root, y, 0);
        
        if (xParse.first && yParse.first && xParse.first != yParse.first && xParse.second == yParse.second)
            return true;
        
        return false;
        
    }
};
