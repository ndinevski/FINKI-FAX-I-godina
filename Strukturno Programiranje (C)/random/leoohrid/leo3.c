#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int isPrime(int n)
{
	int i;
	for(i=2;i<=n/2;i++)
	{
		if(n%i!=0)
			continue;
		else
			return 0;
	}
	return 1;
}

int arrayFunction(int *a, int n){
    int i,j,max=0,min=10000;
    for(i=0;i<n;i++){
        if(isPrime(a[i])){
            if(a[i]>max){
                max=a[i];
            }
            if(a[i]<min){
                min=a[i];
            }
        }
    }
    for(i=0;i<n;i++){
        if (isPrime(a[i])){
            if(i<=n+1){
                for (j=i-1;j<n-1;j++) {  
                    a[j] = a[j+1];  
                }
            }
        }
    }
    return (max+min);   
}
int main()
{
    int n,i;
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("The sum of the max prime and min prime numbers is: %d\n", arrayFunction(a, n));
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    return 0;
}