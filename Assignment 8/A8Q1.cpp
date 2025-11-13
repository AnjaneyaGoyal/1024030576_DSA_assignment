#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int element) {
        data = element;
        left = nullptr;
        right = nullptr;
    }
    
};

Node*root=NULL;
Node*insert(Node*node,int element){
    if(node==nullptr){
        return new Node(element);
    }else if(element>node->data){
        node->right=insert(node->right,element);
    }else{
        node->left=insert(node->left,element);
    }
    return node;
}
void inorder(Node* node){
    if(node!=nullptr){
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
}
void postorder(Node* node){
    if(node!=nullptr){
        inorder(node->left);
        inorder(node->right);
        cout<<node->data<<" ";
    }
}
void preorder(Node* node){
    if(node!=nullptr){
        cout<<node->data<<" ";
        inorder(node->left);
        inorder(node->right);
    }
}
Node* search(Node*node,int k){
    while(node!=nullptr && k!=node->data){
        if(k<node->data){
            return search(node->left,k);
        }else {
            return search(node->right,k);
        }
    }
    return node;
}

int main(){
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Root: " << root->data << endl;
    inorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";
    preorder(root);
    cout<<"\n";

    Node*p=search(root,30);
    return 0;
}