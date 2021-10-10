#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
};

bool areIdentical(node * root1, node *root2){
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;
    return (root1->data == root2->data && areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right) );
}

bool isSubtree(node *T, node *S){
    if (S == NULL) return true;
    if (T == NULL) return false;
    if (areIdentical(T, S)) return true;
 
    return isSubtree(T->left, S) || isSubtree(T->right, S);
}
 
node* newNode(int data){
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
 
int main(){
    node *T = newNode(26);
    T->right = newNode(3);
    T->right->right = newNode(3);
    T->left = newNode(10);
    T->left->left = newNode(4);
    T->left->left->right = newNode(30);
    T->left->right = newNode(6);
 
    node *S = newNode(10);
    S->right= newNode(6);
    S->left = newNode(4);
    S->left->right = newNode(30);
 
    if (isSubtree(T, S)) cout << "Tree 2 is subtree of Tree 1";
    else cout << "Tree 2 is not a subtree of Tree 1";
 
    return 0;
}