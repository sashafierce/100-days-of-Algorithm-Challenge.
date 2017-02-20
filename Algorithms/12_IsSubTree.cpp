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
bool isSame(node *t1 , node * t2){
    if(t1 == NULL || t2 == NULL ) {
        if(t1 == NULL && t2 == NULL)
            return true ;
        }
    else {
    if(t1->val == t2->val && isSame(t1->left , t2->left) && isSame(t1->right , t2->right))
        return true ;
    }
    return false;

}
bool isSubtree(node *t1 , node * t2){
     if(t1 == NULL || t2 == NULL ) {
        if(t1 == NULL && t2 == NULL)
            return true ;
        }
        else {
            if(t1->val == t2->val && isSame(t1 , t2) ) return true ;
            else if(isSubtree(t1->left , t2)) return true ;
            if(isSubtree(t1->left , t2)) return true ;
        }

    return false;
}
int main()
{
    struct node *t1 = new_node(3);
    t1->left = new_node(2);
    t1->right = new_node(1);
    t1->left->right = new_node(20);
    struct node *t2 = NULL;
    if(isSubtree(t1,t2)) cout<<"yes";
    else cout<<"no";
    return 0;
}
