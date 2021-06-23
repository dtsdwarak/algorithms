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
    
    int sum = 0;
    stack<TreeNode*> s;
    
    void traverseLeftTree(TreeNode* root) {
        
        TreeNode *node = root;
        bool treeTraversed = false;
        
        while(node->left) {
            treeTraversed = true;
            if (node->right)
                s.push(node->right);
            s.push(node);
            node = node->left;
        }
        
        if (node->right)
            s.push(node->right);
        s.push(node);
        
        if (treeTraversed && !node->left && !node->right)
            sum += node->val;
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        traverseLeftTree(root);
        
        while(!s.empty()) {
            
            root = s.top();
            s.pop();
            
            if (root->right && !s.empty() && root->right == s.top()) {
                TreeNode *temp = s.top();
                s.pop();
                s.push(root);
                root = temp;
                traverseLeftTree(root);
            }
            
        }
        
        return sum;
    }
};
