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
    
    multiset<int> elements;
    
    void traverseTree(TreeNode* root) {
        
        if (!root)
            return;
        
        elements.insert(root->val);
        traverseTree(root->left);
        traverseTree(root->right);
        
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
     
        traverseTree(root1);
        traverseTree(root2);
        
        vector<int> v(elements.begin(), elements.end());
        return v;
    }
};
