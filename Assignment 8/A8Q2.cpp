#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int element) {
        data = element;
        left = right = NULL;
    }
};

Node* root = NULL;

Node* insert(Node* node, int element) {
    if (node == NULL){
        return new Node(element);
    }
    if (element < node->data){
        node->left = insert(node->left, element);
    }
    else if (element > node->data){
        node->right = insert(node->right, element);
    }
    return node;
}

Node* search(Node* node, int k) {
    while (node != NULL && node->data != k) {
        if (k < node->data){
            node = node->left;
        }
        else{
            node = node->right;
        }
    }
    return node;
}

int maxsum(Node* node) {
    if (node == NULL) {
        cout << "Empty"<<"\n";
        return -1;
    }
    while (node->right != NULL){
        node = node->right;
    }
    return node->data;
}

int minsum(Node* node) {
    if (node == NULL) {
        cout << "Empty"<<"\n";
        return -1;
    }
    while (node->left != NULL){
        node = node->left;
    }
    return node->data;
}

Node* inorderSuccessor(Node* root, Node* target) {
    Node* succ = NULL;
    while (root != NULL) {
        if (target->data < root->data) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* target) {
    Node* pred = NULL;

    while (root != NULL) {
        if (target->data > root->data) {
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pred;
}

int main() {
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    Node* p = search(root, 30);

    int t = maxsum(root);
    int l = minsum(root);

    cout << "Maximum element is: " << t << "\n";
    cout << "Minimum element is: " << l << "\n";

    return 0;
}
