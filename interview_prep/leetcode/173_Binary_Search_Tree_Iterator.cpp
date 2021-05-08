/**
 * Reference -
 * https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
 *
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
class BSTIterator {
public:
    
    stack<TreeNode*> s;
    TreeNode *current;
    
    BSTIterator(TreeNode* root) {
        s.push(root);
        current = root->left;
    }
    
    int next() {
        while(current) {
            s.push(current);
            current = current->left;
        }
        TreeNode* x = s.top();
        s.pop();
        current = x->right;
        return x->val;
    }
    
    bool hasNext() {
        return current || !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
