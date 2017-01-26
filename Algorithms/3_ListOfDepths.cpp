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
int calc_level(struct node *root){
    if(root == NULL ) return 0;
    else return max(calc_level(root->left) , calc_level(root->right) ) + 1;
}
void levelOrder(list<struct node *> a[] , struct node *root , int level, int l){
    if(root == NULL)
        return;
    else {
            a[level-l].push_back(root);
            levelOrder(a , root->left , level , l-1) ;
            levelOrder(a , root->right , level , l-1) ;
    }
}
void print_list(list<struct node *> a){
    list<struct node *>::iterator i = a.begin();
    for( ; i != a.end() ; i++)
        cout<<(*i)->val<<" ";
    cout<<endl;
}
int main() {

    int i , n;

    struct node *root = new_node(6);
    root->left = new_node(7);
    root->left->left = new_node(10);
    struct node *z = new_node(4); z->left = new_node(5);
    root->right = z;

    int l = calc_level(root);
    list<struct node *> a[1000];
    levelOrder(a , root , l , l );
    for(i = 0 ; i < l ; i++) {
        cout<<"Level "<<i+1<<" : ";
        print_list(a[i]);
    }
    //delete a;
    return 9;
}
