#include<iostream>
#include<stdlib.h>
#include <list>
using namespace std;
struct node {
    int val;
    int height;
    struct node *left ;
    struct node *right ;
};
struct node *new_node(int v){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->val = v;
    n->height =  -1 ;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int calc_height(struct node *root){
    if(root == NULL ) return 0;
    else {
        if(root->left != NULL && root->left->height != -1 ) {
            root->height = root->left->height ;
        }
        else {
            root->height = calc_height(root->left);
        }
         if(root->right != NULL && root->right->height != -1 ) {
            root->height = max(root->right->height , root->height)  + 1;
        }
        else {
            root->height = max(calc_height(root->right) , root->height)  + 1;
        }

        return root->height;
    }
}

bool isBalanced(struct node *root ) {
    if(root  == NULL ) return true ;
    else if (root->left == NULL && root->right != NULL ) {
        return root->right->height < 2;
    }
    else if(root->left != NULL && root->right == NULL){
        return root->left->height  < 2;
    }
    else {
        return (abs(root->left->height  - root->right->height ) < 2) && isBalanced(root->left) && isBalanced(root->right);
    }
}

int main() {

    struct node *root = new_node(6);
    root->left = new_node(7);
    struct node * p = root->left->left = new_node(10);
    p->right = new_node(2);
    struct node *z = new_node(4); z->left = new_node(5);
    1root->right = z;

    int l = calc_height(root);
    if(isBalanced(root) == true )
    cout<<"BALANCED";
    else cout<<"NOT BALANCED";
     return 9;
}

