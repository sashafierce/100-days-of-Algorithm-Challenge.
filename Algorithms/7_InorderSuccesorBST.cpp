#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include <limits.h>
using namespace std;
struct node {
    int val;
    struct node *left ;
    struct node *right ;
    struct node *parent ;
};
struct node *new_node(int v , struct node *p){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->val = v;
    n->left = NULL;
    n->right = NULL;
    n->parent = p ;
    return n;
}
struct node * inorderSucc(struct node *root , struct node *n){
    if(n == NULL)  return NULL ;
    else {
        if(n->right != NULL){
            struct node *t = n->right;
            while(t->left != NULL )
                 t = t->left;
            return t;
        }
        else {
            struct node *ch = n;
            struct node *p = n->parent ;
            while( p!=NULL && ch == p->right ) {
                ch =  p ;
                p = p->parent;
            }

                return p;
        }
    }
}
int main() {

    int num ;
    struct node *root = new_node(6 , NULL );
    root->left = new_node(1 , root );
    root->right = new_node(10 , root );
    root->left->right  = new_node(4, root->left );
    root->right->left  = new_node(7 , root->right );
    root->right->left  = new_node(7 , root->right );
    struct node *ans = inorderSucc(root , root->right);
    if(ans == NULL ) printf("NULL\n");
    else
    printf("%d\n", ans->val);
    return 9;
}
