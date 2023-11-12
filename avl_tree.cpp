#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    int height; // Height of the node

    TreeNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

// Function to get the height of a node
int height(TreeNode* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Function to get the balance factor of a node
int getBalanceFactor(TreeNode* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to right rotate subtree rooted with y
TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Function to left rotate subtree rooted with x
TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Function to insert a key into AVL tree
TreeNode* insert(TreeNode* node, int key) {
    // Perform standard BST insertion
    if (node == nullptr)
        return new TreeNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicate keys not allowed
        return node;

    // Update height of current node
    node->height = 1 + std::max(height(node->left), height(node->right));

    // Get the balance factor
    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return unchanged node pointer
    return node;
}

// Function to find the node with the minimum key value
TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;

    // Find the leftmost leaf node
    while (current->left != nullptr)
        current = current->left;

    return current;
}

// Function to delete a key from the AVL tree
TreeNode* deleteNode(TreeNode* root, int key) {
    // Perform standard BST delete
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == nullptr || root->right == nullptr) {
            TreeNode* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else // One child case
                *root = *temp; // Copy the contents of the non-empty child

            delete temp;
        } else {
            // Node with two children, get the inorder successor
            TreeNode* temp = minValueNode(root->right);

            // Copy the inorder successor's key to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node, then return
    if (root == nullptr)
        return root;

    // Update height of the current node
    root->height = 1 + std::max(height(root->left), height(root->right));

    // Get the balance factor
    int balance = getBalanceFactor(root);

    // Left Left Case
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to perform inorder traversal of the AVL tree
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

// Driver program
int main() {
    TreeNode* root = nullptr;

    // Insert keys
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    std::cout << "Inorder traversal after insertion: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Delete keys
    root = deleteNode(root, 30);

    std::cout << "Inorder traversal after deletion: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
