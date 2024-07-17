#include <stdio.h>
int n,a[10][10],t[10],stack[10],indegree[10],top=0;
void indeg(int,int[][10]);
void srcrem(int,int[][10]);
int main()
{
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    indeg(n,a);
    srcrem(n,a);
    printf("Solution:\n");
    for(int k=0;k<n;k++)
        printf("%d",t[k]);
}
void indeg(int n,int a[][10])
{
    int sum;
    for(int i=0;i<n;i++)
    {
        sum=0;
        for(int j=0;j<n;j++)
            sum=sum+a[j][i];
        indegree[i]=sum;
    }
}

void srcrem(int n,int a[][10])
{
    int i,j,v;
    for(i=0;i<n;i++)
    {
        if(indegree[i]==0)
            stack[++top]=i;
    }
    int k=0;
    while(top!=-1)
    {
        v=stack[top--];
        t[k++]=v;
        for(int i=0;i<n;i++)
        {
            if(a[v][i]!=0)
            {
                indegree[i]-=1;
                if(indegree[i]==0)
                    stack[++top]=i;
            }
        }
    }
}