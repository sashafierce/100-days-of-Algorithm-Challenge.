#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct adjListNode{
    int dst ;
    struct adjListNode *next;
};
struct adjList{
   struct adjListNode *head;
};
struct adjListNode *nn(int dst) {
    struct adjListNode *n = ( struct adjListNode*)malloc(sizeof(struct adjListNode));
    n->dst = dst;
    n->next = NULL;
    return n;
}

class Graph
{
    int V;
    struct adjList *arr;
    bool DFSutil(bool visited[] , int s , int d);

    public:
    Graph(int v);
    bool routeExists(int src , int dst );
    bool DFS(int s , int d);
    void addEdge(int src , int dst);
    void print();
};
bool Graph::DFSutil(bool visited[] ,int s , int d){
    visited[s] = true ;
    if(s == d)
        return true;
    struct adjListNode *trav = arr[s].head;
    while(trav != NULL){
        return DFSutil(visited , trav->dst , d);
        trav= trav->next;
    }

}

Graph::Graph(int v) {
    V = v;
    arr =(struct adjList *)malloc((v+1)*sizeof(adjList));
    int i ;
    for(i = 1 ; i <= v ;i++)
        arr[i].head = NULL;

}
bool Graph::DFS(int i , int d){
    bool visited[V+1];
    int j ;
    for(j = 1 ; j <= V ; j++)
        visited[j] = false;
    return DFSutil(visited ,i , d);

}
bool Graph::routeExists(int src , int dst ) {
    return DFS(src ,  dst );
}
void Graph::addEdge(int src , int dst){
    struct adjListNode * t = nn(dst);
    t->next  = arr[src].head ;
     arr[src].head  = t;
}

void Graph::print() {
    int i ;
    for(i = 1 ; i <= V; i++) {
        struct adjListNode *trav = arr[i].head;
        while(trav != NULL) {
            cout<<trav->dst<<" ";
            trav= trav->next;
        }
        cout<<endl;
    }
}
int main()
{
    int v ;
    cin>>v;
    Graph g(5);
    g.addEdge(1 , 3);
    g.addEdge(1 , 2);
    g.addEdge(2 , 3);
    g.addEdge(3 , 4);
    //g.print();
    int src , dst;
    cin>>src>>dst;
    if(g.routeExists(src , dst) == true) cout<<"yes";
    else cout<<"no";
    return 7; // make > 0
}
