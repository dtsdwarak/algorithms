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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if ((p == nullptr) ^ (q == nullptr))
            return false;
        
        stack<TreeNode*> ps,qs;
        ps.push(p);
        qs.push(q);
        
        while(!ps.empty() && !qs.empty()) {
        
            TreeNode *pNode = ps.top(); ps.pop();
            TreeNode *qNode = qs.top(); qs.pop();
            
            if ((pNode == nullptr) ^ (qNode == nullptr))
                return false;
            
            if (pNode && qNode && pNode->val != qNode->val)
                return false;
            
            if(pNode) {
                ps.push(pNode->left); ps.push(pNode->right);
            }
            if(qNode) {
                qs.push(qNode->left); qs.push(qNode->right);
            }
            
        }
        
        if (!ps.empty() || !qs.empty())
            return false;
        
        return true;
    }
};
