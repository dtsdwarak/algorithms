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
class FindElements {
public:
    
    TreeNode *treeRoot;
    
    void recoverTree(TreeNode *root, int value) {
        
        if (!root)
            return;
        
        root->val = value;
        recoverTree(root->left, 2*value + 1);
        recoverTree(root->right, 2*value + 2);
        
    }
    
    FindElements(TreeNode* root) {
        treeRoot = root;
        recoverTree(treeRoot, 0);
    }
    
    bool find(TreeNode *root, int target) {
        
        if (!root)
            return false;
        
        if (root->val == target)
            return true;
        
        return find(root->left, target) || find(root->right, target); 
        
    }
    
    bool find(int target) {
        return find(treeRoot, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
