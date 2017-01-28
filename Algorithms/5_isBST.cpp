#include<iostream>
#include<stdlib.h>
#include <list>
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
bool isBST(struct node *root ) {
    if(root  == NULL ) return true ;
    else{
        bool ans = true;
         if (root->right != NULL ) {
            ans = ans && root->right->val > root->val;
        }
        if(root->left != NULL){
           ans = ans && root->left->val < root->val ;
        }
        return ans && isBST(root->left) && isBST(root->right);
    }
}
int main() {

    struct node *root = new_node(6);
    root->left = new_node(1);
    struct node * p = root->left->left = new_node(0);
    p->right = new_node(2);
    struct node *z = new_node(40); z->left = new_node(15);
    root->right = z;

    if(isBST(root) == true )
    cout<<"BST";
    else cout<<"NOT BST";
     return 9;
}
