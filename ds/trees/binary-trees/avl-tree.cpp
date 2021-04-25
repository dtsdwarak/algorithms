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

struct Node {
  
  int val;
  int height;
  Node *right;
  Node *left;
  
  Node(int value) {
    this->val = value;
    height = 0;
    right = left = NULL;
  }
};

int getHeight(Node *node) {
  if (!node)
    return 0;
  return node->height;
}

int getHeightBalance(Node *node) {
  if (!node)
    return 0;
  return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node *node) {
  
  Node *x = node->left;
  Node *right = x->right;

  node->left = right;
  x->right = node;
  
  node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  
  return x;
}

Node* leftRotate(Node *node) {
  
  Node *x = node->right;
  Node *left = x->left;
  
  node->right = left;
  x->left = node;
  
  node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  
  return x;
}

Node* insert(Node *root, int value) {

    if (!root)
      return new Node(value);
    
    if (value < root->val)
      root->left = insert(root->left, value);
    else if (value > root->val) 
      root->right = insert(root->right, value);
    else // Equal keys not allowed
      return root;
    
    // Adjust height
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    
    int heightBalance = getHeightBalance(root);
    
    // left left
    if (heightBalance > 1 && value < root->left->val) {
        return rightRotate(root);
    }
    
    // left right
    if (heightBalance > 1 && value > root->left->val) {
        root->left = rightRotate(root->left);
        return leftRotate(root);
    }
    
    // right right
    if (heightBalance < -1 && value > root->right->val) {
        return leftRotate(root);
    }
    
    // right left
    if (heightBalance < -1 && value < root->right->val) {
      root->right = leftRotate(root->right);
      return rightRotate(root);
    }
    
    return root;
}

Node* findSuccessor(Node *root) {
    
    while(root->left)
      root = root->left;
    
    return root;
}

Node* deleteNode(Node *root, int value) {
  
  if (!root) {
      cout<<value<<" not found.";
      return root;
  }
  
  if (value < root->val)
    root->left = deleteNode(root->left, value);
  else if (value > root->val)
    root->right = deleteNode(root->right, value);
  else {
      
      // If node to be deleted has atmost 1 child
      if (!root->left || !root->right) {
      
         Node* temp = (!root->left) ? root->right : root->left;
         
         // If there are no children
         if (!temp) {
            temp = root;
            root = NULL;
         }
         else 
            root = temp;
        
        delete(temp);
      }
      else { // Node has two children
          
          Node *temp = findSuccessor(root->right);
          
          root->val = temp->val;
          root->right = deleteNode(root->right, temp->val);
      }
    
  }
  
  if (!root)
      return NULL;
      
  // Adjust height
  root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
  
  int heightBalance = getHeightBalance(root);
  
  // left left
  if (heightBalance > 1 && getHeightBalance(root->left) >= 0) {
      return rightRotate(root);
  }
  
  // left right
  if (heightBalance > 1 && getHeightBalance(root->left) < 0) {
      root->left = rightRotate(root->left);
      return leftRotate(root);
  }
  
  // right right
  if (heightBalance < -1 && getHeightBalance(root->left) <= 0) {
      return leftRotate(root);
  }
  
  // right left
  if (heightBalance < -1 && getHeightBalance(root->left) > 0) {
    root->right = leftRotate(root->right);
    return rightRotate(root);
  }
  
  return root;
}

void preOrder(Node *root) {

    if (!root)
      return;
      
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node *root = NULL;
    
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    
    preOrder(root);
    
    root = deleteNode(root, 5);
    root = deleteNode(root, 4);
    
    preOrder(root);
    
    return 0;
    
}
