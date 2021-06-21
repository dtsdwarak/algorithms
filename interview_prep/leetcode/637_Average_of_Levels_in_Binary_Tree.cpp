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
    vector<double> averageOfLevels(TreeNode* root) {
        
        stack<TreeNode*> current, nextLevel;
        current.push(root);
        
        vector<double> levelAverage;
        
        while (!current.empty() || !nextLevel.empty()) {
            
            double sum = 0;
            int numberOfElementsInLevel = current.size();
        
            while(!current.empty()) {

                TreeNode *node = current.top();
                current.pop();
                
                sum += node->val;

                if (node->left)
                    nextLevel.push(node->left);
                if (node->right)
                    nextLevel.push(node->right);
            }
        
            levelAverage.push_back(sum/numberOfElementsInLevel);
            swap(current, nextLevel);
        }
        
        return levelAverage;
        
    }
};

