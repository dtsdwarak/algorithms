/**
 * Reference - 
 * https://www.geeksforgeeks.org/diameter-of-a-binary-tree/
 * 
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
    
    int fetchDiameterOfBinaryTree(TreeNode *root, int &height) {
        
        int leftHeight=0, rightHeight=0, leftDiameter=0, rightDiameter=0;
        
        if (!root) {
            height = 0;
            return 0;
        }
        
        leftDiameter  = fetchDiameterOfBinaryTree(root->left, leftHeight);
        rightDiameter = fetchDiameterOfBinaryTree(root->right, rightHeight);
        
        height = max(leftHeight, rightHeight) + 1;
        
        return max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int height = 0;
        return fetchDiameterOfBinaryTree(root, height);
    }
};
