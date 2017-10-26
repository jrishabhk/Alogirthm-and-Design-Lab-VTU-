#include<stdio.h>
int u,v,i,j,n,ne=1;
int visited[10]={0},min,mincost=0,cost[10][10];
 void main()
 {
     printf("enter the no of vertices\n");
     scanf("%d",&n);
     printf("enter the adjacency matrix\n");
     for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
     {
      scanf("%d",&cost[i][j]);
      if(cost[i][j]==0)
       cost[i][j]=999;
       }
       visited[1]=1;
       while(ne<n)
       {
         for(i=1,min=999;i<=n;i++)
         for(j=1;j<=n;j++)
         if((cost[i][j]<min)&&(visited[i]==1))
         {
            min=cost[i][j];
            u=i;
            v=j;
         }
         if(visited[u]==0||visited[v]==0)
         {
           printf("edge:%d(%d,%d)cost:%d\n",ne++,u,v,min);
           mincost+=min;
           visited[v]=1;
         }
         cost[u][v]=cost[v][u]=999;
       }
       printf("the minimum cost is %d\n",mincost);
   } 
