/**
 * Definition for a binary tree node.
 * 
 * This is same as "530. Minimum Absolute Difference in BST" - 
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/
 * 
 *  struct TreeNode {
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
    
    vector<int> treeElements;
    
    void inOrderTraversal(TreeNode *root) {
        
        if (!root)
            return;
        
        inOrderTraversal(root->left);
        treeElements.push_back(root->val);
        inOrderTraversal(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        
        inOrderTraversal(root);
        int minDiff = INT_MAX;
        
        for(int i=0; i<treeElements.size()-1;i++)
            minDiff = min(minDiff, treeElements[i+1]-treeElements[i]);
        
        return minDiff;
        
    }
};
