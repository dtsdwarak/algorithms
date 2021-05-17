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

void inOrder(TreeNode *root) {
    
    stack<TreeNode*> s;
    
    while(root || !s.empty()) {
    
        while(root) {
            s.push(root);
            root = root->left;
        }
        
        root = s.top();
        s.pop();
        
        cout<<root->val<<" ";
        
        root = root->right;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    inOrder(root);
    return 0;
    
}
