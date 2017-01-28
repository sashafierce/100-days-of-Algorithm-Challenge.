#include<bits/stdc++.h>
using namespace std;
int main()
{
    int  i , j ,  mx, n , ind;
    cin>>n;
    int a[5005] ;
    for(i = 1 ; i <= n ; i++)
        cin>>a[i];
    int cnt[5005] = {0};

    for(i =  1; i <= n ; i++) {
        mx = 0; ind = i ;
        int h[5005] = {0};
         for(j = i ; j <= n ; j++) {
            h[a[j]]++ ;
            if(h[a[j]] ==  mx && a[ind] > a[j] ){
                ind = j ;
            }
            else if(h[a[j]] >  mx){
                mx = h[a[j]];
                ind = j ;
            }
            //cout<<a[ind]<<endl;
            cnt[a[ind]]++ ;
        }
    }
    for(i = 1 ; i <= n ; i++)  cout<<cnt[i]<<" ";
    cout<<endl;
    return 0;
}
