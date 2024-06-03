#include <iostream>
#include <vector>

using namespace std;

// Template class for a node in the BST/AVL tree
template<typename t>
class node {
public:
    t data;          // Node data
    node* left;      // Pointer to the left child
    node* right;     // Pointer to the right child

    // Default constructor
    node() {
        left = nullptr;
        right = nullptr;
    }

    // Constructor with data initialization
    node(t val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Template class for a Binary Search Tree (BST)
template<typename t>
class BST {
private:
    node<t>* root;  // Root node of the BST

    // Helper function to add a node with a specific value
    void addhelper(node<t>* x, t val) {
        node<t>* newnode = new node<t>(val);
        if (val <= x->data) {
            if (x->left == nullptr)
                x->left = newnode;
            else
                addhelper(x->left, val);
        } else if (val > x->data) {
            if (x->right == nullptr)
                x->right = newnode;
            else
                addhelper(x->right, val);
        }
    }

    // Helper function to find the maximum value in the BST
    t maxhelper(node<t>* x) {
        if (x->right == nullptr)
            return x->data;
        else
            return maxhelper(x->right);
    }

    // Helper function to find the minimum value in the BST
    t minhelper(node<t>* x) {
        if (x->left == nullptr)
            return x->data;
        else
            return minhelper(x->left);
    }

    // Helper function to find the height of the BST
    int height(node<t>* x) {
        if (x == nullptr)
            return -1;
        int lt = height(x->left);
        int rt = height(x->right);
        return max(lt + 1, rt + 1);
    }

    // Helper function to remove a node with a specific value
    node<t>* removehelper(node<t>* x, t val) {
        if (x == nullptr)
            return x;
        else if (val < x->data)
            x->left = removehelper(x->left, val);
        else if (val > x->data)
            x->right = removehelper(x->right, val);
        else {
            // Node with one or no child
            if (x->left == nullptr) {
                node<t>* temp = x;
                x = x->right;
                delete temp;
            } else if (x->right == nullptr) {
                node<t>* temp = x;
                x = x->left;
                delete temp;
            } else {
                // Node with two children
                t maxval = maxhelper(x->left);
                x->data = maxval;
                x->left = removehelper(x->left, maxval);
            }
        }
        return x;
    }

    // Helper function to search for a node with a specific value
    int searchhelper(node<t>* x, t val) {
        if (x == nullptr)
            return -1;
        else if (val < x->data)
            return searchhelper(x->left, val);
        else if (val > x->data)
            return searchhelper(x->right, val);
        else {
            return 1;
        }
    }

    // Helper function for preorder traversal
    void preorder(node<t>* x) {
        if (x == nullptr)
            return;
        cout << x->data << " ";
        preorder(x->left);
        preorder(x->right);
    }

public:
    // Constructor
    BST() {
        root = nullptr;
    }

    // Check if the BST is empty
    bool isempty() {
        return root == nullptr;
    }

    // Insert a new value into the BST
    void insert(t val) {
        node<t>* newnode = new node<t>(val);
        if (isempty()) {
            root = newnode;
            return;
        }
        node<t>* temp = root, * prev = nullptr;
        while (temp != nullptr) {
            prev = temp;
            if (val <= temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (val <= prev->data)
            prev->left = newnode;
        else
            prev->right = newnode;
    }

    // Add a new value using the helper function
    void add(t val) {
        if (root == nullptr) {
            node<t>* newnode = new node<t>(val);
            root = newnode;
            return;
        }
        addhelper(root, val);
    }

    // Get the maximum value in the BST
    t getmax() {
        return maxhelper(root);
    }

    // Get the minimum value in the BST
    t getmin() {
        return minhelper(root);
    }

    // Remove a node with a specific value
    node<t>* remove(t val) {
        root = removehelper(root, val);
        return root;
    }

    // Get the height of the BST
    int getheight() {
        return height(root);
    }

    // Search for a node with a specific value
    int search(t val) {
        return searchhelper(root, val);
    }

    // Display the BST using preorder traversal
    void display() {
        preorder(root);
        cout << endl;
    }
};

// Template class for an AVL tree
template<typename t>
class AVL {
private:
    node<t>* root;  // Root node of the AVL tree

    // Helper function to get the height of a node
    int height(node<t>* x) {
        if (x == nullptr)
            return -1;
        int lt = height(x->left);
        int rt = height(x->right);
        return max(lt + 1, rt + 1);
    }

    // Helper function to get the maximum value in the AVL tree
    int getmax(node<t>* x) {
        if (x->right == nullptr)
            return x->data;
        else
            return getmax(x->right);
    }

    // Helper function to get the balance factor of a node
    int getbalancefactor(node<t>* x) {
        if (x == nullptr)
            return -1;
        else
            return height(x->left) - height(x->right);
    }

    // Right rotation helper function
    node<t>* rightrotation(node<t>* x) {
        node<t>* y = x->left;
        node<t>* temp = y->right;
        y->right = x;
        x->left = temp;
        return y;
    }

    // Left rotation helper function
    node<t>* leftrotation(node<t>* x) {
        node<t>* y = x->right;
        node<t>* temp = y->left;
        y->left = x;
        x->right = temp;
        return y;
    }

    // Helper function to insert a node and balance the AVL tree
    node<t>* inserthelper(node<t>* x, t val) {
        if (x == nullptr) {
            return new node<t>(val);
        } else if (val <= x->data) {
            x->left = inserthelper(x->left, val);
        } else if (val > x->data) {
            x->right = inserthelper(x->right, val);
        }

        int bf = getbalancefactor(x);

        // Balance the tree
        if (bf > 1 && val < x->left->data) {
            return rightrotation(x);
        } else if (bf < -1 && val > x->right->data) {
            return leftrotation(x);
        } else if (bf > 1 && val > x->left->data) {
            x->left = leftrotation(x->left);
            return rightrotation(x);
        } else if (bf < -1 && val < x->right->data) {
            x->right = rightrotation(x->right);
            return leftrotation(x);
        }
        return x;
    }

    // Helper function for preorder traversal
    void preorder(node<t>* x) {
        if (x == nullptr)
            return;
        cout << x->data << " ";
        preorder(x->left);
        preorder(x->right);
    }

    // Helper function to remove a node and balance the AVL tree
    node<t>* removehelper(node<t>* x, t val) {
        if (x == nullptr)
            return nullptr;
        else if (val < x->data) {
            x->left = removehelper(x->left, val);
        } else if (val > x->data) {
            x->right = removehelper(x->right, val);
        } else {
            if (x->left == nullptr) {
                node<t>* r = x;
                x = x->right;
                delete r;
            } else if (x->right == nullptr) {
                node<t>* r = x;
                x = x->left;
                delete r;
            } else {
                int maxval = getmax(x->left);
                x->data = maxval;
                x->left = removehelper(x->left, maxval);
            }
        }

        int bf = getbalancefactor(x);

        // Balance the tree
        if (bf > 1 && val <= x->left->data) {
            return rightrotation(x);
        } else if (bf < -1 && val > x->right->data) {
            return leftrotation(x);
        } else if (bf > 1 && val > x->left->data) {
            x->left = leftrotation(x->left);
            return rightrotation(x);
        } else if (bf < -1 && val <= x->right->data) {
            x->right = rightrotation(x->right);
            return leftrotation(x);
        }
        return x;
    }

public:
    // Constructor
    AVL() {
        root = nullptr;
    }

    // Check if the AVL tree is empty
    bool isempty() {
        return root == nullptr;
    }

    // Add a new value into the AVL tree
    void add(t val) {
        root = inserthelper(root, val);
    }

    // Display the AVL tree using preorder traversal
    void display() {
        preorder(root);
        cout << endl;
    }

    // Remove a node with a specific value
    void remove(t val) {
        root = removehelper(root, val);
    }
};

// Function to perform max heapify on a vector
template<class t>
void maxheapify(vector<t>& v, int n, int rt) {
    int l = rt * 2 + 1, r = rt * 2 + 2;
    int maxx = rt;
    if (l < n && v[l] > v[maxx])
        maxx = l;
    if (r < n && v[r] > v[maxx])
        maxx = r;
    if (maxx != rt) {
        swap(v[rt], v[maxx]);
        maxheapify(v, n, maxx);
    }
}

// Function to build a max heap from a vector
template<class t>
void buildmaxheapify(vector<t>& v, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxheapify(v, n, i);
    }
}

// Template class for a max heap
template<class t>
class heap {
    vector<t> v;  // Vector to store heap elements

public:
    // Add a new value to the heap
    void add(t val) {
        if (v.empty())
            v.push_back(val);
        else {
            v.push_back(val);
            buildmaxheapify(v, v.size());
        }
    }

    // Remove the maximum value from the heap
    void remove() {
        if (!v.empty()) {
            swap(v[0], v[v.size() - 1]);
            v.pop_back();
            buildmaxheapify(v, v.size());
        } else {
            cout << "It is empty!!\n";
        }
    }

    // Display the heap elements
    void display() {
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Create a max heap
    heap<int> b;

    // Add elements to the heap
    b.add(30);
    b.add(35);
    b.add(40);
    b.add(20);
    b.add(10);
    b.add(50);
    b.add(15);

    // Remove elements from the heap
    b.remove();
    b.remove();

    // Display the heap
    b.display();
}
