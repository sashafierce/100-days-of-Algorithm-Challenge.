
#include<iostream>
#include<algorithm>
using namespace std;
void swap(int * a, int *b){
    int t  = *a ;
    *a = *b;
    *b = t;
}
void swap(double * a, double *b){
    double t  = *a ;
    *a = *b;
    *b = t;
}
int partiton(double a[] , int w[]  , int lo  , int hi) {
    int p = hi ;
    int i = lo -1 , j = lo;
    while(j < hi) {
        if(a[j] > a[p]){
            i++ ;
            swap(&a[i],&a[j] );
            swap(&w[i] ,&w[j]);
        }
        j++;
    }
    i++;
    swap(&a[i] , &a[p]);
    swap(&w[i] , &w[p]);
    return i;

}
void qsort(double a[] , int w[] , int lo , int hi) {
    if(lo < hi ) {
        int p = partiton(a , w, lo , hi);
        qsort(a , w,  lo , p-1) ;
        qsort(a , w, p+1 , hi);
    }
}
double fks(int w[] , int v[] , int n , int W) {
    double a[n+1] ;
    int i ;
    double max_val = 0.0 ;
    for(i = 0 ; i < n ; i++)
        a[i] = (double)v[i] / w[i];

    qsort(a , w, 0 , n-1);
    int wt = 0;
    i = 0;
    while(wt < W && i < n) {
        if(w[i] <= W-wt){
            wt += w[i] ;
            max_val += a[i] * w[i];
        }
        else {
            max_val += (W - wt) * a[i];
            wt = W;
        }
        i++ ;
    }
    return max_val;

}
int main()
{
    int n , i , W;
    cin>>n;
    int w[n+1] , v[n+1];
    for(i = 0 ; i < n ; i++) {
        cin>>w[i]>>v[i];
    }
    cin>>W;
    cout<<fks(w , v , n ,W);
    return 0;
}
