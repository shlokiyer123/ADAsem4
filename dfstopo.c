#include <stdio.h>
int n,a[10][10],s[10],res[10],top=0;
void dfs(int,int,int[][10]);
void dfs_tp(int,int[][10]);
int main()
{
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the adjaceny matrix\n");
    for(int i=0;i<n;i++)
        {for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);}
    dfs_tp(n,a);
    printf("Solution: ");
    for (int i = n - 1; i >= 0; i--) {
    printf("%d ", res[i]);
    }
    return 0;
}
//mark all as unvisited and call the main dfs function for the unvisited
void dfs_tp(int n,int a[][10])
{
    for(int i=0;i<n;i++)
        s[i]=0;
    for(int j=0;j<n;j++)
        {
            if(s[j]==0)
                dfs(j,n,a);
        }
}
//marks the called vertex and increments stackzaza
void dfs(int j,int n,int a[][10])
{
    s[j]=1;
    for(int i=0;i<n;i++)
        {
            if(a[j][i]==1 && s[i]==0)
                dfs(i,n,a);
        }
    res[top++]=j;
}