#include <stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[],int size,int heappoint)
{
    int largest=heappoint;
    int left=2*heappoint+1;
    int right=2*heappoint+2;
    if(left < size && arr[left]>arr[largest])
        largest=left;
    if(right < size && arr[right]>arr[largest])
        largest=right;
    if(largest!=heappoint)
    {
        swap(&arr[largest],&arr[heappoint]);
        heapify(arr,size,largest);
    }
}
void heap_sort(int arr[],int size)
{
    for(int i=size/2-1;i>=0;i--)
        heapify(arr,size,i);
    for(int i=size-1;i>=0;i--)
    {   
         swap(&arr[0],&arr[i]);
         heapify(arr,i,0);
    }
}
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[] = { 14,8,3,9,44,32};
    int N = sizeof(arr) / sizeof(arr[0]);
    heap_sort(arr, N);
    printf("Sorted array is\n");
    printArray(arr, N);
}