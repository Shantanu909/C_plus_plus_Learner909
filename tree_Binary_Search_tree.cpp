#include <iostream>

// Define a binary search tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() : root(nullptr) {}

    // Function to insert a value into the binary search tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Helper function for inserting a value recursively
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    // Function to search for a value in the binary search tree
    bool search(int value) {
        return searchRecursive(root, value);
    }

    // Helper function for searching a value recursively
    bool searchRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }
};

int main() {
    BinarySearchTree bst;

    // Insert elements into the binary search tree
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Search for elements
    int searchValue = 60;
    if (bst.search(searchValue)) {
        std::cout << searchValue << " found in the binary search tree." << std::endl;
    } else {
        std::cout << searchValue << " not found in the binary search tree." << std::endl;
    }

    return 0;
}
