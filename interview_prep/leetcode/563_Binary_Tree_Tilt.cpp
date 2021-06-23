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

    
    // Pair of - sum of actual left, sum of Tilt left
    pair<int, int> fetchTiltPair(TreeNode *root) {
        
        if (!root)
            return make_pair(0,0);
        
        if (!root->left && !root->right)
            return make_pair(root->val, 0);
        
        pair<int, int> leftPair = fetchTiltPair(root->left);
        pair<int, int> rightPair = fetchTiltPair(root->right);
        
        return make_pair(
                leftPair.first  + rightPair.first  + root->val,
                leftPair.second + rightPair.second + abs(leftPair.first - rightPair.first)
            );
        
    }
    
    int findTilt(TreeNode* root) {
     
        pair<int, int> rootTilt = fetchTiltPair(root);
        return rootTilt.second;
        
    }
};
