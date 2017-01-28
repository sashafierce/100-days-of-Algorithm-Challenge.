#include<iostream>
#include<stdlib.h>
#include <limits.h>
using namespace std;
struct node {
    int val;
    struct node *left ;
    struct node *right ;
};
struct node *new_node(int v){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->val = v;
    n->left = NULL;
    n->right = NULL;
    return n;
}
bool isBST(struct node *root , int mi , int ma ) {
    if(root == NULL ) return true;
    else {
        if(root->val <= mi)  return false ;
        if(root->val > ma ) return false ;
        if( !isBST(root->left , mi, root->val) || !isBST(root->right , root->val , ma) ) return false;
        return true;
    }
}
int main() {

    struct node *root = new_node(6);
    root->left = new_node(1);
    struct node * p = root->left->left = new_node(0);
    p->right = new_node(2);
    struct node *z = new_node(40); z->left = new_node(15);
    root->right = new_node(88);

    if(isBST(root , INT_MIN  , INT_MAX) == true )
     cout<<"BST";
    else cout<<"NOT BST";
     return 9;
}
