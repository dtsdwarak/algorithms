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
    
    vector<string> paths;
    
    void fetchBinaryTreePaths(TreeNode *root, string path) {
        
        if (!root->left && !root->right) {
            paths.push_back(path+"->"+to_string(root->val));
            return;
        }
        
        if (root->left)
            fetchBinaryTreePaths(root->left, path+"->"+to_string(root->val));
        if (root->right)
            fetchBinaryTreePaths(root->right, path+"->"+to_string(root->val));
    
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        if (!root->left && !root->right)
            return vector<string> {to_string(root->val)};
         
        if (root->left)
            fetchBinaryTreePaths(root->left, to_string(root->val));
        if (root->right)
            fetchBinaryTreePaths(root->right, to_string(root->val));
        return paths;
    }
};
