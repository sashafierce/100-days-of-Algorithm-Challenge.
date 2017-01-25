#include<iostream>
#include<stdlib.h>
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
struct node *build_tree(struct node *root , int a[] , int lo  , int hi ){

    if(lo <= hi) {
        int m = lo + (hi - lo )/2 ;
        root = new_node(a[m]);
        root->left = build_tree(root->left , a ,lo , m-1);
        root->right = build_tree(root->right ,a , m+1 , hi);
    }
    return root;
}
void print_tree(struct node *root){
    if(root == NULL) ;
    else {
        cout<<root->val<<" ";
        print_tree(root->left);
        print_tree(root->right);
    }
}
int main() {

    int i , n;
    cin>>n;
    int a[n+7];
    for(i = 0 ; i < n ; i++)  cin>>a[i];
    struct node *root = build_tree(root , a , 0 , n-1);
    print_tree(root);
    return 9;
}
