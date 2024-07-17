#include <stdio.h>
#include <stdlib.h>
int n;
void genperm(int [],int,int);
void swap(int*,int*);
int main()
{
    printf("Enter the amount of elements:\n");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    genperm(arr,0,n-1);
    free(arr);
    return 0;
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void genperm(int arr[],int start,int end)
{
    if(start==end)
    {
        for(int i=0;i<n;i++)
            printf("%d\t",arr[i]);
        printf("\n");
    }
    else
    {   
        for(int i=start;i<=end;i++)
        {
            swap(&arr[start],&arr[i]);
            genperm(arr,start+1,end);
            swap(&arr[start],&arr[i]);
        }
    }
}