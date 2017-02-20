#include<iostream>
#include<stdlib.h>
#include<unordered_map>
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

int pathSum(struct node *n , int sum , int running_sum , unordered_map<int  , int >   m) {
    if(n == NULL) return 0;
    int c = 0;
    running_sum += n->val;
    if(running_sum == sum) c+= 1;
    else if(m.count(running_sum - sum ) > 0) c += m.count(running_sum - sum );
    m[running_sum ] += 1;
    c += pathSum(n->left , sum , running_sum , m);
   c += pathSum(n->right , sum , running_sum , m);
   m[running_sum] -= 1;
   return c;
}

int main() {

    int i , n , k ;
    k = 4;      // sum
    struct node *root = new_node(4);
    root->left = new_node(9);
    root->right = new_node(1);
    root->left->left = new_node(-9);
    root->left->left->right = new_node(0);
    root->left->right = new_node(-5);
    root->right->right = new_node(3);
    unordered_map<int  , int >   m;
    int ans = pathSum(root , k , 0 , m );
    cout<<ans<<endl;
    return 0;
}

