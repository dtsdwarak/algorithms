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
    
    void TraverseTree(TreeNode* root, set<int> &elements) {
        if (!root)
            return;
        
        elements.insert(root->val);
        
        TraverseTree(root->left, elements);
        TraverseTree(root->right, elements);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        
        set<int> elements;
        TraverseTree(root, elements);
        
        if (elements.size() < 2)
            return -1;
        return *next(elements.begin(), 1);
    }
};
