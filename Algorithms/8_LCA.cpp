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
int height(struct node *root){
    if(root == NULL ) return 0;
    else return max(height(root->left) , height(root->right) ) + 1;
}
struct node* climb(struct node* n , int x){
    while(x > 0 && n != NULL) {
            n = n->parent ; x -= 1;
    }
    return n;
}
struct node* lca(struct node* root , struct node* p ,struct node* q) {
    int maxH = height(root);
    int dq  = maxH-height( q); int dp = maxH - height(p);
    int delta = dp - dq;
    struct node * deep = delta > 0 ? p : q;
    struct node * shall = delta > 0 ? q : p;
    deep = climb(deep , abs(delta));
    while(deep != shall && deep != NULL && shall != NULL) {
        deep = deep->parent ; shall = shall->parent;
    }
    if(deep == NULL || shall == NULL) return NULL ;

    return shall;

}
int main() {

    int num ;
    struct node *root = new_node(6 , NULL );
    root->left = new_node(19 , root );
    root->right = new_node(1 , root );
    root->left->right  = new_node(4, root->left );
    root->left->left = new_node(8, root->left );
    root->right->left  = new_node(7 , root->right );
    struct node *ans = lca(root ,root , root->left->left);

    if(ans == NULL ) printf("NULL\n");
    else
    printf("%d\n", ans->val);
    return 9;
}
