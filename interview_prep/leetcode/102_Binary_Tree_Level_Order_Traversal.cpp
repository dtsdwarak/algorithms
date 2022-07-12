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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> q1, q2;
        
        if (root)
            q1.push(root);
        
        vector<vector<int>> levelOrder;
        
        while(!q1.empty()) {
        
            vector<int> levelList;
            
            while(!q1.empty()) {

                TreeNode *node = q1.front(); q1.pop();
                levelList.push_back(node->val);
                
                if (node->left)
                    q2.push(node->left);
                if (node->right)
                    q2.push(node->right);
            }
            
            levelOrder.push_back(levelList);
            swap(q1, q2);
        }
        
        return levelOrder;
        
    }
};
