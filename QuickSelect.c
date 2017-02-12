#include<stdio.h>
#include<stdlib.h>
// quick select k larget no.
void swap(int *a , int *b) {
    int t = *a;
    *a = *b ;
     *b = t;
}
int quickSelect(int a[] , int k  ,int lo  , int hi){
    if(lo <= hi) {
        int p = partition(a , lo , hi);
        if(p == k) return a[p] ;
        else if(p < k) quickSelect(a , k , p+1  , hi);
        else quickSelect(a , k, lo , p-1);
    }
}
int kthLargest(int a[] ,int n ,  int k){
    return quickSelect(a ,n-k,0 , n-1 );
}
int partition(int a[] , int lo , int hi) {
    int pi = rand()%(hi-lo+1) + lo ;
    swap(&a[pi] ,&a[hi]);
    pi = hi ;
    int i = lo-1 ; int j = lo;
    while(j < hi) {
          if(a[j] <= a[pi]) {
                i++ ;
                swap(&a[i],&a[j]);
            }
           j++;
    }
    i++;
    swap(&a[hi] , &a[i]);
    return i;
}
int main()
{
    int n = 7;
    int a[] = { 1 , 0 , 33 , 12 , 10 , 100 , -3};
    int k = 2 ;
    int e ;
     e = kthLargest( a , n , k );
    printf("%d\n",e);
    return 0;
}
