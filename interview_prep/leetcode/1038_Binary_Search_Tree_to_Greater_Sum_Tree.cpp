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
    
    set<int, greater<int>> s;
    unordered_map<int,int> sumMap;
    
    void traverseTree(TreeNode* root) {
        
        if (!root)
            return;
        
        s.insert(root->val);
        
        traverseTree(root->left);
        traverseTree(root->right);
    }
    
    void setSumValues() {
        
        int sum = 0;
        
        for(int i: s) {
            sum += i;
            sumMap[i] = sum;
        }
        
    }
    
    void createGST(TreeNode *root) {
        
        if (!root)
            return;
        
        root->val = sumMap[root->val];
        
        createGST(root->left);
        createGST(root->right);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        
        traverseTree(root);
        setSumValues();
        createGST(root);
        
        return root;
        
    }
};
