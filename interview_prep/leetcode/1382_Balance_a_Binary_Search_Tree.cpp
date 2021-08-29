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
    
    vector<TreeNode*> nodes;
    
    void storeTreeNode(TreeNode* root) {
        if (!root)
            return;
        storeTreeNode(root->left);
        nodes.push_back(root);
        storeTreeNode(root->right);
        
    }
    
    TreeNode* getTree(int low, int high) {
        
        if (low > high)
            return nullptr;
        
        int mid = (low + high)/2;
        TreeNode* node = nodes[mid];
        node->left = getTree(low, mid-1);
        node->right = getTree(mid+1, high);
        
        return node;
        
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        storeTreeNode(root);
        return getTree(0, nodes.size()-1);
        
        
    }
};
