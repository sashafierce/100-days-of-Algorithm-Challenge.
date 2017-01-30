#include<stdio.h>
int dthdigit(int num , int d){
    int x;
    while(num > 0 && d > 0) {
        x = num % 10 ;
        num /= 10 ;
        d -= 1;
    }
    return x;
}
void CountingSort(int a[] , int n , int d) {
    int c[11] , i;
    for(i = 0 ; i < 10 ; i++)
        c[i] = 0;
    for(i = 0 ; i < n ; i++)
        c[dthdigit(a[i] , d)] += 1;

    for(i = 1 ; i < 10 ; i++) {
        c[i] += c[i-1];
    }
    int b[n+1] ;
    for(i = n-1 ; i >= 0 ; i--) {
        b[c[dthdigit(a[i] , d)] - 1] = a[i];
        c[dthdigit(a[i] , d)] -= 1;
    }
    for(i = 0 ; i < n ; i++) a[i] = b[i];
}
int main()
{
    int n , i;
    scanf("%d" , &n);
    int a[n+1] , b[n+1];
    for(i = 0 ; i < n ; i++) {
        scanf("%d" , &a[i]);
        b[i] = a[i];
    }
    int d = 0 ;
    int num = a[0];
    while(num > 0) {
        num /= 10 ;
        d += 1;
    }
    for(i = 1 ; i <= d ; i++) {
        CountingSort(b , n , i);
    }
    for(i = 0 ; i < n; i++)
        printf("%d ",b[i]);
    return 0;
}
