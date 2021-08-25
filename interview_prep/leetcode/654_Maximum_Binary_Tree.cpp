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
    
    TreeNode* constructMaxBinaryTree(vector<int> &nums, int start, int end) {
        
        int maxVal = INT_MIN;
        int maxIndex = nums[start];
        
        for(int i=start; i<=end; i++) {
            if (maxVal < nums[i]) {
                maxVal = nums[i];
                maxIndex = i;
            }
        }
        
        TreeNode *node = new TreeNode{maxVal};
        if (start<=maxIndex-1)
            node->left = constructMaxBinaryTree(nums, start, maxIndex-1);
        if (maxIndex+1<=end)
            node->right = constructMaxBinaryTree(nums, maxIndex+1, end);
        
        return node;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return constructMaxBinaryTree(nums, 0, nums.size() -1);
    }
};
