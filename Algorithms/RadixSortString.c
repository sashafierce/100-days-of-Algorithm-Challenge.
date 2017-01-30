# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
void swapS(char *str1, char *str2)
{
  char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
  free(temp);
}
void swapI(char *a , char *b) {
	char t = *a;
	*a  = *b ;
	*b = t;
}
void radix_sort(char **,int,int);
void counting_sort(char **a , int n , int k , int d) {
    int c[100] , i;
    char b[n+2][k+2];          
    for(i = 0 ; i < 100 ; i++)
        c[i] = 0;
    for(i = 0 ; i < n ; i++)
        c[a[i][d] - 32] += 1;      // d -> 0 to k-1

    for(i = 1 ; i < 100 ; i++) {
        c[i] += c[i-1];
    }	
    for(i = n-1 ; i >= 0 ; i--) {
        strcpy(b[c[a[i][d] - 32]] , a[i]) ;
        c[a[i][d] - 32] -= 1;
    }
    
    for(i = 0 ; i < n ; i++) {
	strcpy(a[i] , b[i+1]);	
    }
}
void counting_sort2(char **a , int n , int k , int d) {
    int c[100] , i , j ,x;           
    for(i = 0 ; i < 100 ; i++)
        c[i] = 0;
    for(i = 0 ; i < n ; i++)
        c[a[i][d] - 32] += 1;      // d -> 0 to k-1

    for(i = 1 ; i < 100 ; i++) {
        c[i] += c[i-1];
    }	
	
	j = c[a[n-1][d] - 32] - 1;
	x = 0 ;
	int pi = n-1;
    while(x < n) {
	
       swapS(a[j] , a[pi]);
	if(pi == j && pi > 0) pi--;
	j = c[a[pi][d] - 32] -1;
        c[a[pi][d] - 32] -= 1;
	x++;
    }
    
  
}
int main()
{
	  char **input;
	  char ch=' ';
	  int n,k,i,j;
	  srand(time(NULL));
	  scanf("%d",&n);
	  scanf("%d",&k);
	  input = (char **)malloc(n*sizeof(char *));
	  for(i=0;i<n;i++)
	    {
		      input[i]=(char *)malloc((k+1)*sizeof(char));
		      for(j=0;j<k;j++)
			input[i][j]=(rand()%95)+32;
		      input[i][k]='\0';
	    }
	    for(i=0;i<n;i++)
	    {
	      	printf("%s\n",input[i]);
	    }
	    printf("\n");
	     radix_sort(input,n,k);
	     for(i=0;i<n;i++)
	    {
	       printf("%s\n",input[i]);
	    }
	  
	  return 0;
}
void radix_sort(char **input,int n,int k)
{
	  int i ;
	  for(i=k-1;i>=0;i--) {
		counting_sort(input , n , k , i);	
	  }

	  // part 2
	 /* for(i=k-1;i>=0;i--) {
		counting_sort2(input , n , k , i);	
	  }*/
}
