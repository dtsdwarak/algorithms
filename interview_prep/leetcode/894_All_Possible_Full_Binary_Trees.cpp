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
 *
 * Reference - 
 * https://duoertai.gitbooks.io/leetcode-solutions/content/tree/all-possible-full-binary-trees.html
 *
 */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if (!(n & 1)) {
            return vector<TreeNode*>();
        }
        
        if (n == 1)
            return vector<TreeNode*>{new TreeNode(0)};
        
        vector<TreeNode*> trees;
        
        for(int i=1; i<=n-2;i++) {
            
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n-i-1);
            
            for(TreeNode *l : left) {
                for(TreeNode *r : right) {
                    
                    TreeNode *node = new TreeNode(0);
                    node->left = l;
                    node->right = r;
                    
                    trees.push_back(node);
                    
                }
            }
        }
        
        return trees;
        
    }
};
