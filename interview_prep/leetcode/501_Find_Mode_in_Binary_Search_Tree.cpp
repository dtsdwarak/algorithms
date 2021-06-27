/**
 *
 * Reference -
 * https://evelynn.gitbooks.io/google-interview/content/find-mode-in-binary-search-tree.html 
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
class Solution {
public:
    
    void fetchNumberFrequency(TreeNode* root, unordered_map<int, int> &frequency) {
        
        if (!root)
            return;
        
        if (frequency.find(root->val) != frequency.end())
            frequency[root->val]++;
        else
            frequency.insert({root->val, 1});
        
        fetchNumberFrequency(root->left, frequency);
        fetchNumberFrequency(root->right, frequency);
        
    }
        
    
    vector<int> findMode(TreeNode* root) {
        
        unordered_map<int, int> frequency;
        fetchNumberFrequency(root, frequency);
        
        map<int, vector<int>> frequencyVector;
        
        for(auto i: frequency) {
            
            if (frequencyVector.find(i.second) != frequencyVector.end())
                frequencyVector[i.second].push_back(i.first);
            else
                frequencyVector.insert({i.second, vector<int>{i.first}});
            
        }
        
        return prev(frequencyVector.end())->second; 
        
    }
};
