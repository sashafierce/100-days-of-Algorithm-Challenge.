#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {
    int val;
    struct node *left ;
    struct node *right ;
};
int n1 = 4;
int n2 = 2;
struct node *new_node(int v){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->val = v;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void preorder(char a[] , node *t , int i ) {
    if(t == NULL )
     a[i] = '\\';
   else {
    a[i] = t->val;
    preorder(a , t->left , i+1);
    preorder(a , t->right , i+1);
   }
}
bool isSubstring(char a[] , char b[]) {
    int i ;
    int c = 0;
    int j= 0 ;
    for(i = 0 ; i <= n2-n1 ; i++) {
        while(j < n2 && a[j] == b[j] ) {
            j++ ;
        }
        if(j == n2) {
            return true;
        }
        else j = 0;
    }
}
bool isSubtree(node *t1 , node * t2){
     if(t1 == NULL || t2 == NULL ) {
        if(t1 == NULL && t2 == NULL)
            return true ;
        }
        else {
            char a[100] , b[100];
            preorder(a , t1, 0);
            preorder(b, t2, 0);
            return (isSubstring(a , b));
        }

    return false;
}
int main()
{

    struct node *t1 = new_node(3);
    t1->left = new_node(2);
    t1->right = new_node(1);
    t1->left->right = new_node(20);
     struct node *t2 = new_node(3);
    t2->left = new_node(2);
    if(isSubtree(t1,t2)) cout<<"yes";
    else cout<<"no";
    return 0;
}
