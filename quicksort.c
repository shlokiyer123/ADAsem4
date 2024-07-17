#include <stdio.h>
#include<time.h>
int a[20],n;
int partition(int [],int, int);
void quick_sort(int [],int,int);
void swap(int*,int*);
int main()
{
    int i;
    clock_t start, end;
    double time_taken;
    printf("Enter the no. of elements:");
    scanf("%d", &n);
    printf("Enter the array elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    start = clock();
    quick_sort(a, 0, n - 1);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted array:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("Time taken to sort: %f seconds\n", time_taken);
    return 0;
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void quick_sort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=partition(a,low,high);
        quick_sort(a,low,mid-1);
        quick_sort(a,mid+1,high);
    }
}
int partition(int a[],int low, int high)
{
    int pivot=a[low];
    int i=low;
    int j=high+1;
    while(i<=j)
    {
        do{
            i+=1;
        }while(a[i]<pivot && i<=high);
        do{
            j-=1;
        }while(a[j]>pivot && j>=low);
        if(i<j)
            swap(&a[i],&a[j]);
    }
    swap(&a[j],&a[low]);
    return j;
}