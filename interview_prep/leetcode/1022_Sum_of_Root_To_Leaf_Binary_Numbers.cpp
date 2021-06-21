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
    
    vector<string> getBinaryStrings(TreeNode *root) {
        
        if (!root->left && !root->right)
            return vector<string> {to_string(root->val)};
        
        vector<string> leftNumbers, rightNumbers;
        
        if (root->left)
            leftNumbers = getBinaryStrings(root->left);
        if (root->right)
            rightNumbers = getBinaryStrings(root->right);
        
        leftNumbers.insert(leftNumbers.end(), rightNumbers.begin(), rightNumbers.end());
        
        for(int i=0; i<leftNumbers.size(); i++)
            leftNumbers[i] = to_string(root->val) + leftNumbers[i];
        
        
        return leftNumbers;
    }
    
    
    int decimalNumber(string binaryNumber) {
        
        int sum=0;
        int base = 1;
        
        for(int i=binaryNumber.length()-1; i>-1; i--) {
            sum += (binaryNumber[i] - '0') * base;
            base *= 2;
        }
        
        return sum;
        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        
        vector<string> binaryNumbers = getBinaryStrings(root);
        int sum = 0;
        for (string i: binaryNumbers)
            sum += decimalNumber(i);
        return sum;
        
    }
};

