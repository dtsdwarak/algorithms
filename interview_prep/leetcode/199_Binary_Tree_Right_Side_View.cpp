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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        
        if (root)
            q1.push(root);
        
        
        while(!q1.empty()) {
            
            ans.push_back(q1.back()->val);
            
            while(!q1.empty()) {

                TreeNode *node = q1.front();
                q1.pop();

                if(node->left)
                    q2.push(node->left);
                if (node->right)
                    q2.push(node->right);

            }

            swap(q1, q2);
        }
        
        return ans;
        
    }
};

