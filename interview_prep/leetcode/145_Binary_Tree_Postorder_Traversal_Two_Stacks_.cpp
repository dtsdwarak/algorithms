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
    vector<int> postorderTraversal(TreeNode* root) {
        
        if (!root)
            return vector<int>();
        
        stack<TreeNode*> s1, s2;
        
        s1.push(root);
        
        while(!s1.empty()) {
            
            TreeNode *current = s1.top();
            s1.pop();
            
            s2.push(current);
            
            if (current->left)
                s1.push(current->left);
            if (current->right)
                s1.push(current->right);
        }
        
        vector<int> ans;
        
        while(!s2.empty()) {
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        
        return ans;
        
    }
};
