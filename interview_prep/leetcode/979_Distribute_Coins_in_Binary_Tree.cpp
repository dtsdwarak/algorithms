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
    
    int moves=0;
    
    int distributeCoininBST(TreeNode* root) {
        if (!root)
            return 0;
        
        int lMoves = distributeCoininBST(root->left);
        int rMoves = distributeCoininBST(root->right);
        
        moves += abs(lMoves) + abs(rMoves);
        
        return root->val + lMoves + rMoves - 1;
    }
    
public:
    int distributeCoins(TreeNode* root) {
        
        moves += distributeCoininBST(root);
        return moves;
    }
};
