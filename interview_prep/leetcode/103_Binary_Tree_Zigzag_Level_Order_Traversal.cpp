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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        stack<TreeNode*> stk;
        stack<TreeNode*> stk2;
        
        stk.push(root);
        
        vector<vector<int> > ans;
        
        
        bool rightToLeft = true;
        
        do {
            
            vector<int> currentRow;
            
            while(!stk.empty()) {
            
                TreeNode *node = stk.top();
                stk.pop();
                
                if (!node)
                    continue;

                currentRow.push_back(node->val);

                if (rightToLeft) {
                    if (node->left)
                        stk2.push(node->left);
                    if (node->right)
                        stk2.push(node->right);
                } else {
                    if (node->right)
                        stk2.push(node->right);
                    if (node->left)
                        stk2.push(node->left);
                }
            
            }
        
            stk = stk2;
            stk2 = stack<TreeNode*>();
            
            if (currentRow.size() > 0)
                ans.push_back(currentRow);
            rightToLeft = !rightToLeft;
            
        } while(!stk.empty());
        
        return ans;
        
    }
};
