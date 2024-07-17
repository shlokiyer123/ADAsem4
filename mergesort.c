#include <stdio.h>
#include <time.h>
int a[10],c[10],v[10],n;
void divide(int ,int,int []);
void mergesort(int,int,int,int []);
int main()
{
    clock_t start,end;
    printf("Enter the amount of elements:\n");
    scanf("%d",&n);
    printf("Enter the unsorted array:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    start= clock();
    divide(0,n-1,a);
    end=clock();
    double timetaken= (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted array:");
    for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
    }
    printf("\n");
    printf("Time taken to sort: %f seconds\n", timetaken);
    return 0;
}
void divide(int start,int end,int a[])
{
    if(start<end)
    {
        int mid=(start+end)/2;
        divide(start,mid,a);
        divide(mid+1,end,a);
        mergesort(start,mid,end,a);
    }
}
void mergesort(int start,int mid,int end,int a[])
{
    int i=start;
    int k=start;
    int j=mid+1;
    while(i<=mid && j<=end)
    {
        if(a[i]<a[j])
        {
            c[k++]=a[i];
            i++;
        }
        else
        {
            c[k++]=a[j];
            j++;
        }
    }
    while(i<=mid)
    {
        c[k++]=a[i];
        i++;
    }
    while (j<=end)
    {
        c[k++]=a[j];
        j++;
    }
    for(int l=start;l<=end;l++)
        a[l]=c[l];
}