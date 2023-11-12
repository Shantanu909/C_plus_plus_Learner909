#include <iostream>

// Define a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    // Function to insert a value into the binary tree
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

    // Function to perform an in-order traversal of the binary tree
    void inOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            std::cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    // Wrapper function for in-order traversal
    void inOrderTraversal() {
        inOrderTraversal(root);
        std::cout << std::endl;
    }

    // Function to perform a pre-order traversal of the binary tree
    void preOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    // Wrapper function for pre-order traversal
    void preOrderTraversal() {
        preOrderTraversal(root);
        std::cout << std::endl;
    }

    // Function to perform a post-order traversal of the binary tree
    void postOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            std::cout << node->data << " ";
        }
    }

    // Wrapper function for post-order traversal
    void postOrderTraversal() {
        postOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree tree;

    // Insert elements into the binary tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "In-order traversal: ";
    tree.inOrderTraversal();

    std::cout << "Pre-order traversal: ";
    tree.preOrderTraversal();

    std::cout << "Post-order traversal: ";
    tree.postOrderTraversal();

    return 0;
}
