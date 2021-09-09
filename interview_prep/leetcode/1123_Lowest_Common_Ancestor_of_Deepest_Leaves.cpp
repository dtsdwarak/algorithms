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
    
    map<int, vector<TreeNode*> > levelNode;
    map<TreeNode*, string> leafPath;

    void fillLevel(TreeNode* root, int level, string path) {
        
        if (!root)
            return;
        
        if (!root->left && !root->right) {

            // levelNode fill up
            
            if (levelNode.find(level) == levelNode.end())
                levelNode[level] = vector<TreeNode*>{root};
            else
                levelNode[level].push_back(root);
            
            // Path fill up
            leafPath[root] = ((path == "") ? "" : (path + "-")) + to_string(root->val);
        }
        else {
            
            fillLevel(root->left, level+1,((path == "") ? "" : (path + "-")) + to_string(root->val));
            fillLevel(root->right, level+1, ((path == "") ? "" : (path + "-")) + to_string(root->val));
        }
    }
    
    int findAncestor(vector<TreeNode*> &deepestLeaves) {
                
        vector<string> pathStrings;
        for(TreeNode* node : deepestLeaves)
            pathStrings.push_back(leafPath[node]);
        
        vector<vector<int>> paths;
        
        for(string path : pathStrings) {
            
            vector<int> intPath;
            stringstream ss(path);
            string substr;
            
            
            while(getline(ss, substr, '-'))
                intPath.push_back(stoi(substr));
            
            paths.push_back(intPath);
        }
        
        bool loopBroken = false;
        int numberIndex=0;
        
        for(;numberIndex<paths[0].size(); numberIndex++) {
            int currentNumber = paths[0][numberIndex];
            int currentPathIndex=1;
            for(;currentPathIndex<paths.size() && paths[currentPathIndex][numberIndex] == currentNumber; currentPathIndex++);
            if (currentPathIndex != paths.size()) {
                loopBroken = true;
                break;
            }
        }
        
        if (loopBroken)
            return paths[0][numberIndex-1];
        
        return paths[0][numberIndex-2];
    }
    
    TreeNode* findNode(TreeNode* root, int val) {
        
        if (!root)
            return nullptr;
        
        if (root->val == val)
            return root;
        
        TreeNode* leftVal =  findNode(root->left, val);
        TreeNode* rightVal = findNode(root->right, val);
        
        return (leftVal) ? leftVal : rightVal; 

    }
    
    TreeNode* findCommonAncestor(TreeNode* root) {
        
        vector<TreeNode*> deepestLeaves = prev(levelNode.end())->second;
        
        if (deepestLeaves.size() == 1)
            return deepestLeaves[0];

        
        int ancestor = findAncestor(deepestLeaves);
        
        
        return findNode(root, ancestor);
    }
    
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        fillLevel(root, 0, "");
        return findCommonAncestor(root);
        
    }
};
