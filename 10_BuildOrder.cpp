#include<bits/stdc++.h>
using namespace std;
stack<char> s;
int dfs(int i , vector<char> g[] , int n , int visited[] , vector<char> &projects ,map<char , int> m ){
    if(visited[i] == 1) return 1;
    else if(visited[i] == 0){
        visited[i] = 1;
        int x = g[i].size();
        for(int j = 0 ; j < x; j++) {
            if(dfs(m[g[i][j]] , g ,n, visited , projects , m)) return 1;

        }
        visited[i] = 2;
        s.push(projects[i]);
    }
    return 0;
}
int build_order( vector<char> g[] , int n , vector<char> &p ,map<char,int> m) {
     int c = 0;
     int visited[n] = {0};

     for(int i = 0 ; i < n ; i++) {
        if( !visited[i]  ) {
            int c = dfs(i , g , n, visited , p , m) ;
            if(c == 1) return c ;
        }
     }
    return c;
}

int main()
{
    map<char , int> m;
    int n , e;
    scanf("%d %d" ,&n,&e);
    vector<char> projects;
    vector<char> g[n];
    for(int i = 0 ; i < n ; i++ ){
        projects.push_back('a' + i);
        m[projects[i]] = i;
    }
    for(int i = 0 ; i < e ; i++ ) {
        char a , b;
        cin>>a>>b;
        g[m[a]].push_back(b);
    }
    int f =  build_order(g , n ,projects, m);
    if(f == 1) {
        printf("error");
        return 0;
    }
    while(!s.empty()){
        char c = s.top();
        s.pop();
        printf("%c " ,c);
    }

    return 0;
}
