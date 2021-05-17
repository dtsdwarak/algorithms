/*
	author: dtsdwarak
*/

# include <bits/stdc++.h>

#define pval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using namespace std;

typedef long long ll;

// Vector output template
template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

struct TreeNode {
  int val;
  TreeNode *left, *right;  
  
  TreeNode(int value) {
    this->val = value;
    left = right = nullptr;
  }
};

bool checkIfValidBST(TreeNode *root, TreeNode *min, TreeNode *max) {
    
    if (!root)
        return true;
        
    if ((min && root->val <= min->val) || (max && root->val >= max->val))
        return false;
    
    return checkIfValidBST(root->left, nullptr, root) &&
           checkIfValidBST(root->right, root, nullptr);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    
    cout<<"Given Tree is a validBST = "<<checkIfValidBST(root, nullptr, nullptr);
    return 0;
}
