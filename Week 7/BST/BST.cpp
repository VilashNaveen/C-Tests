#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left , *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root == nullptr) {
        return;
    }
    traverseInOrder(root->left);
    cout << root->key << " " ;
    traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node == nullptr) {
        struct node *newNode = new struct node;
        newNode->key = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        node = newNode;
    }
    else if (node->key <= key) {
        node->right =  insertNode(node->right,key);
    }
    else {
        node->left = insertNode(node->left,key);

    }
    return node;
}
//find minimum value of tree
int treeMin (struct node *root) {
    if (root == nullptr) {
        return 10000;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return root->key;
    }
    int left = treeMin(root->left);
    int right = treeMin(root->right);
    return min(left, min(right,root->key));
}
// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == nullptr) {
        return root;
    }
    if (root->key == key) {
        if (root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }
        else if (root->left != nullptr && root->right == nullptr) {
            return root->left;
        }
        else if (root->left == nullptr && root->right != nullptr) {
            return root->right;
        }
        else {
            root->key = treeMin(root->right);
            return deleteNode(root->right, treeMin(root->right));
;        }
    }
    if (root->key >= key) {
        root->left = deleteNode(root->left,key);
    }
    else {
        root->right = deleteNode(root->right,key);
    }
    return root;
}

// Driver code
int main() {

  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);

}