#include <stdio.h>
int num,size,w[10],p[10];
int max(int a,int b)
{
    return (a>b) ? a:b;
}
void knapsack(int,int,int [],int []);
int main()
{
    int num=4;
    int size=8;
    int p[10]={1,2,5,6};
    int w[10]={2,3,4,5};
    knapsack(num,size,w,p);
}
void knapsack(int num,int size,int w[],int p[])
{
    int v[num+1][size+1];   
    for(int i=0;i<=num;i++)
    {
        for(int j=0;j<=size;j++)
        {
            if(i==0||j==0)
                v[i][j]=0;
            else if(w[i-1]<=j)
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i-1]]+p[i-1]);
            else
                v[i][j]=v[i-1][j];
        }
    }
    for(int i=0;i<=num;i++)
    {
        for(int j=0;j<=size;j++)
        {
            printf("%d",v[i][j]);
        }printf("\n");
    }
    int k=num,l=size;
    while(k > 0 && l > 0)
    {
        if(v[k][l]==v[k-1][l])
        {    
            printf("%d not included\n",k);
            k--;
        }
        else{
            printf("%d included\n",k);
            k--;
            l=l-w[k];
        }
}
}