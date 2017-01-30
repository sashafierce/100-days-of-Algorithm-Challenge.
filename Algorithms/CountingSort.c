#include<stdio.h>
int main()
{
    int n , i;
    scanf("%d" , &n);
    int a[n+1] , c[11];
    for(i = 0 ; i < 10 ; i++) c[i] = 0;
    for(i = 0 ; i < n ; i++) {
        scanf("%d" , &a[i]);
        c[a[i]] += 1;
    }
    for(i = 1 ; i < 10 ; i++) {
        c[i] += c[i-1];
    }
    int b[n+1] ;
    for(i = n-1 ; i >= 0 ; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]] -= 1;
    }
    for(i = 0 ; i < n; i++) printf("%d ",b[i]);
    return 0;

}
