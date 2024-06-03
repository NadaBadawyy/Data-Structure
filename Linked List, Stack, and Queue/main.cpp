#include <iostream>
using namespace std;

// Node class for representing a node in linked list and other data structures
template<typename t>
class node {
public:
    t data;         // Data of the node
    node* next;     // Pointer to the next node
    node* prev;     // Pointer to the previous node (used in doubly linked list)
    
    // Default constructor
    node() {
        next = nullptr;
        prev = nullptr;
    }
    
    // Parameterized constructor
    node(t val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Linked List class
template<typename t>
class linkedlist {
    node<t>* head;  // Head pointer for the linked list
public:
    // Constructor
    linkedlist() {
        head = nullptr;
    }
    
    // Check if the linked list is empty
    bool isempty() {
        return head == nullptr;
    }
    
    // Check if a value is found in the linked list
    bool isfound(t val) {
        node<t>* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->data == val) {
                found = true;
                break;
            }
            temp = temp->next;
        }
        return found;
    }
    
    // Insert a new node at the beginning of the linked list
    void insertfirst(t val) {
        if (isempty()) {
            node<t>* newnode = new node<t>(val);
            head = newnode;
        } else {
            node<t>* newnode = new node<t>(val);
            newnode->next = head;
            head = newnode;
        }
    }
    
    // Insert a new node at the end of the linked list
    void insertlast(t val) {
        node<t>* temp = head;
        node<t>* newnode = new node<t>(val);
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    
    // Insert a new node before a specific value
    void insertbefore(t val, t item) {
        if (isfound(val)) {
            if (head->data == val) {
                insertfirst(item);
                return;
            }
            node<t>* temp = head;
            node<t>* prev = nullptr;
            while (temp->data != val) {
                prev = temp;
                temp = temp->next;
            }
            node<t>* newnode = new node<t>(item);
            prev->next = newnode;
            newnode->next = temp;
        } else {
            cout << "The item is not found\n";
        }
    }
    
    // Insert a new node at a specific index
    void insert(int idx, t val) {
        int index = -1;
        if (idx > count() || idx < 0)
            cout << "Out of range!!\n";
        else {
            if (idx == 0) {
                insertfirst(val);
            } else if (idx == count()) {
                insertlast(val);
            } else {
                node<t>* prev = head;
                while (index != idx - 2) {
                    index++;
                    prev = prev->next;
                }
                node<t>* newnode = new node<t>(val);
                newnode->next = prev->next;
                prev->next = newnode;
            }
        }
    }
    
    // Count the number of nodes in the linked list
    int count() {
        node<t>* temp = head;
        int cnt = 0;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    
    // Display the linked list
    void display() {
        node<t>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Delete the first node in the linked list
    void deletefirst() {
        if (isempty()) {
            cout << "List is empty\n";
        } else {
            node<t>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    // Delete the last node in the linked list
    void deletelast() {
        if (isempty()) {
            cout << "List is empty\n";
        } else {
            node<t>* temp = head, * prev = nullptr;
            while (temp->next != nullptr) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
    }
    
    // Delete a node with a specific value
    void delette(t val) {
        if (isempty()) {
            cout << "List is empty\n";
        } else if (!isfound(val)) {
            cout << "The item is not found!!\n";
        } else if (head->data == val) {
            deletefirst();
        } else {
            node<t>* temp = head, * prev = nullptr;
            while (temp->data != val) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
    }
    
    // Search for a value and return its index
    int search(int val) {
        int index = 0;
        if (!isfound(val))
            return -1;
        node<t>* temp = head;
        while (temp->data != val) {
            index++;
            temp = temp->next;
        }
        return index;
    }
};

// Doubly Linked List class
template<typename t>
class doublylinkedlist {
    node<t>* head;  // Head pointer for the doubly linked list
    node<t>* last;  // Last pointer for the doubly linked list
public:
    // Constructor
    doublylinkedlist() {
        head = nullptr;
        last = nullptr;
    }
    
    // Check if the doubly linked list is empty
    bool isempty() {
        return head == nullptr && last == nullptr;
    }
    
    // Check if a value is found in the doubly linked list
    bool isfound(t val) {
        node<t>* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->data == val) {
                found = true;
                break;
            }
            temp = temp->next;
        }
        return found;
    }
    
    // Insert a new node at the beginning of the doubly linked list
    void insertfirst(t val) {
        if (isempty()) {
            node<t>* newnode = new node<t>(val);
            head = newnode;
            last = newnode;
        } else {
            node<t>* newnode = new node<t>(val);
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }
    
    // Insert a new node at the end of the doubly linked list
    void insertlast(t val) {
        node<t>* temp = head;
        node<t>* newnode = new node<t>(val);
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        last = newnode;
    }
    
    // Insert a new node before a specific value
    void insertbefore(t val, t item) {
        if (isfound(val)) {
            if (head->data == val) {
                insertfirst(item);
                return;
            }
            node<t>* temp = head;
            node<t>* prev = nullptr;
            while (temp->data != val) {
                prev = temp;
                temp = temp->next;
            }
            node<t>* newnode = new node<t>(item);
            prev->next = newnode;
            newnode->next = temp;
            temp->prev = newnode;
            newnode->prev = prev;
        } else {
            cout << "The item is not found\n";
        }
    }
    
    // Insert a new node at a specific index
    void insert(int idx, t val) {
        int index = -1;
        if (idx > count() || idx < 0)
            cout << "Out of range!!\n";
        else {
            if (idx == 0) {
                insertfirst(val);
            } else if (idx == count()) {
                insertlast(val);
            } else {
                node<t>* prev = head;
                while (index != idx - 2) {
                    index++;
                    prev = prev->next;
                }
                node<t>* newnode = new node<t>(val);
                newnode->next = prev->next;
                prev->next = newnode;
            }
        }
    }
    
    // Count the number of nodes in the doubly linked list
    int count() {
        node<t>* temp = head;
        int cnt = 0;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    
    // Display the doubly linked list in ascending order
    void display() {
        node<t>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Display the doubly linked list in descending order
    void displaydcs() {
        node<t>* temp = last;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
    
    // Search for a value and return its index
    int search(int val) {
        int index = 0;
        if (!isfound(val))
            return -1;
        node<t>* temp = head;
        while (temp->data != val) {
            index++;
            temp = temp->next;
        }
        return index;
    }
    
    // Delete the first node in the doubly linked list
    void deletefirst() {
        if (isempty()) {
            cout << "List is empty\n";
        } else {
            node<t>* temp = head;
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            delete temp;
        }
    }
    
    // Delete the last node in the doubly linked list
    void deletelast() {
        if (isempty()) {
            cout << "List is empty\n";
        } else {
            node<t>* temp = head, * prev = nullptr;
            while (temp->next != nullptr) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            last = temp->prev;
            delete temp;
        }
    }
    
    // Delete a node with a specific value
    void delette(t val) {
        if (isempty()) {
            cout << "List is empty\n";
        } else if (!isfound(val)) {
            cout << "The item is not found!!\n";
        } else if (head->data == val) {
            deletefirst();
        } else {
            node<t>* temp = head, * prev = nullptr;
            while (temp->data != val) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            if (temp->next != nullptr)
                temp->next->prev = prev;
            if (temp->next == nullptr)
                last = temp->prev;
            delete temp;
        }
    }
};

// Stack class
template<typename t>
class stack {
    node<t>* head;  // Head pointer for the stack
    node<t>* top;   // Top pointer for the stack
    
    // Insert a new node at the beginning of the stack
    void insertfirst(t val) {
        node<t>* newnode = new node<t>(val);
        head = newnode;
    }

public:
    // Constructor
    stack() {
        head = nullptr;
        top = nullptr;
    }
    
    // Check if the stack is empty
    bool isempty() {
        return head == nullptr;
    }
    
    // Check if a value is found in the stack
    bool isfound(t val) {
        node<t>* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->data == val) {
                found = true;
                break;
            }
            temp = temp->next;
        }
        return found;
    }

    // Add a new node to the stack
    void add(t val) {
        if (isempty()) {
            insertfirst(val);
            return;
        }
        node<t>* temp = head;
        node<t>* newnode = new node<t>(val);
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
        top = newnode;
    }

    // Count the number of nodes in the stack
    int count() {
        node<t>* temp = head;
        int cnt = 0;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    
    // Display the stack
    void display() {
        node<t>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Remove the top node from the stack
    void remove() {
        if (isempty()) {
            cout << "List is empty\n";
        } else {
            node<t>* temp = head, * prev = nullptr;
            while (temp->next != nullptr) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            top = prev;
            delete temp;
        }
    }

    // Search for a value and return its index
    int search(int val) {
        int index = 0;
        if (!isfound(val))
            return -1;
        node<t>* temp = head;
        while (temp->data != val) {
            index++;
            temp = temp->next;
        }
        return index;
    }
    
    // Get the value of the top node
    t gettop() {
        if (top == nullptr)
            return -1;
        else
            return top->data;
    }
};

// Queue class
template<typename t>
class queue {
    node<t>* head;  // Head pointer for the queue
    
    // Insert a new node at the beginning of the queue
    void insertfirst(t val) {
        node<t>* newnode = new node<t>(val);
        head = newnode;
    }
public:
    // Constructor
    queue() {
        head = nullptr;
    }
    
    // Check if the queue is empty
    bool isempty() {
        return head == nullptr;
    }
    
    // Check if a value is found in the queue
    bool isfound(t val) {
        node<t>* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->data == val) {
                found = true;
                break;
            }
            temp = temp->next;
        }
        return found;
    }

    // Add a new node to the queue
    void add(t val) {
        if (isempty()) {
            insertfirst(val);
            return;
        }
        node<t>* temp = head;
        node<t>* newnode = new node<t>(val);
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    // Count the number of nodes in the queue
    int count() {
        node<t>* temp = head;
        int cnt = 0;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    
    // Display the queue
    void display() {
        node<t>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Remove the front node from the queue
    void remove() {
        if (isempty()) {
            cout << "List is empty\n";
        } else {
            node<t>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Search for a value and return its index
    int search(int val) {
        int index = 0;
        if (!isfound(val))
            return -1;
        node<t>* temp = head;
        while (temp->data != val) {
            index++;
            temp = temp->next;
        }
        return index;
    }
    
    // Get the value of the front node
    t getfront() {
        return head->data;
    }
};

// Priority Queue class
template<typename t>
class priorityqueue {
    node<t>* head;  // Head pointer for the priority queue
public:
    // Constructor
    priorityqueue() {
        head = nullptr;
    }
    
    // Check if the priority queue is empty
    bool isempty() {
        return head == nullptr;
    }
    
    // Add a new node to the priority queue
    void add(t val) {
        if (isempty()) {
            head = new node<t>(val);
            return;
        } else {
            node<t>* newnode = new node<t>(val);
            node<t>* temp = head, * prev = nullptr;
            if (val < head->data) {
                newnode->next = head;
                head = newnode;
                return;
            }
            while (temp != nullptr && val >= temp->data) {
                prev = temp;
                temp = temp->next;
            }
            newnode->next = temp;
            prev->next = newnode;
        }
    }
    
    // Display the priority queue
    void display() {
        node<t>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // Priority Queue demonstration
    priorityqueue<int> l;
    l.add(20);
    l.add(50);
    l.add(10);
    l.add(40);
    l.add(30);
    l.add(15);
    l.display();

    return 0;
}
