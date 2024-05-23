Exp 15 Write a Program to implement Binary Search Tree operations
#include <iostream>

using namespace std;

// Node structure for Binary Search Tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    TreeNode* root;

    // Private helper functions for recursive implementation
    TreeNode* insertRecursive(TreeNode* node, int data) {
        if (node == nullptr) {
            return new TreeNode(data);
        }
        if (data < node->data) {
            node->left = insertRecursive(node->left, data);
        } else if (data > node->data) {
            node->right = insertRecursive(node->right, data);
        }
        return node;
    }

    TreeNode* findMinNode(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNodeRecursive(TreeNode* node, int data) {
        if (node == nullptr) {
            return nullptr;
        }
        if (data < node->data) {
            node->left = deleteNodeRecursive(node->left, data);
        } else if (data > node->data) {
            node->right = deleteNodeRecursive(node->right, data);
        } else {
            // Case 1: Node with no child or only one child
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            // Case 2: Node with two children
            TreeNode* temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = deleteNodeRecursive(node->right, temp->data);
        }
        return node;
    }

    bool searchRecursive(TreeNode* node, int data) {
        if (node == nullptr) {
            return false;
        }
        if (data < node->data) {
            return searchRecursive(node->left, data);
        } else if (data > node->data) {
            return searchRecursive(node->right, data);
        } else {
            return true;
        }
    }

    void inorderRecursive(TreeNode* node) {
        if (node != nullptr) {
            inorderRecursive(node->left);
            cout << node->data << " ";
            inorderRecursive(node->right);
        }
    }

    void preorderRecursive(TreeNode* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderRecursive(node->left);
            preorderRecursive(node->right);
        }
    }

    void postorderRecursive(TreeNode* node) {
        if (node != nullptr) {
            postorderRecursive(node->left);
            postorderRecursive(node->right);
            cout << node->data << " ";
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    // Function to insert a value into the BST
    void insert(int data) {
        root = insertRecursive(root, data);
    }

    // Function to delete a value from the BST
    void remove(int data) {
        root = deleteNodeRecursive(root, data);
    }

    // Function to search for a value in the BST
    bool search(int data) {
        return searchRecursive(root, data);
    }

    // Function to perform inorder traversal of the BST
    void inorderTraversal() {
        inorderRecursive(root);
        cout << endl;
    }

    // Function to perform preorder traversal of the BST
    void preorderTraversal() {
        preorderRecursive(root);
        cout << endl;
    }

    // Function to perform postorder traversal of the BST
    void postorderTraversal() {
        postorderRecursive(root);
        cout << endl;
    }

    // Function to find the minimum value in the BST
    int findMin() {
        if (root == nullptr) {
            cout << "Tree is empty\n";
            return -1;
        }
        TreeNode* minNode = findMinNode(root);
        return minNode->data;
    }

    // Function to find the maximum value in the BST
    int findMax() {
        if (root == nullptr) {
            cout << "Tree is empty\n";
            return -1;
        }
        TreeNode* maxNode = root;
        while (maxNode->right != nullptr) {
            maxNode = maxNode->right;
        }
        return maxNode->data;
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal: ";
    bst.inorderTraversal(); // Output: 20 30 40 50 60 70 80

    cout << "Preorder traversal: ";
    bst.preorderTraversal(); // Output: 50 30 20 40 70 60 80

    cout << "Postorder traversal: ";
    bst.postorderTraversal(); // Output: 20 40 30 60 80 70 50

    cout << "Minimum element: " << bst.findMin() << endl; // Output: Minimum element: 20
    cout << "Maximum element: " << bst.findMax() << endl; // Output: Maximum element: 80

    bst.remove(30);
    cout << "Inorder traversal after deleting 30: ";
    bst.inorderTraversal(); // Output: 20 40 50 60 70 80

    cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not found") << endl; // Output: Search for 40: Found
    cout << "Search for 100: " << (bst.search(100) ? "Found" : "Not found") << endl; // Output: Search for 100: Not found

    return 0;
}