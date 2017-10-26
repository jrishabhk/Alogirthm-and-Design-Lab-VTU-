#include<iostream>
using namespace std;
const int MAX=10;
class topo
{
 private: int a[MAX][MAX];
          int n;
          int soln[MAX];
          int indeg[MAX];
          int visited[MAX];
 public: void readadj();
         int indegree(int);
         void toposort();
 };
 void topo::readadj()
 {
   cout<<"enter the no of vertices:";
   cin>>n;
   cout<<"enter the adjacency matrix:"<<endl;
   for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
   cin>>a[i][j];
   for(int i=1;i<=n;i++)
   visited[i]=0;
  }
  void topo::toposort()
  { int k=1;
    int j;
    for(int i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
       {
         if(visited[j]==0)
         { 
           indeg[j]=indegree(j);
           if(indeg[j]==0)
           break;
         }
       }
        soln[k++]=j;
        visited[j]=1;
        for(int w=1;w<=n;w++)
        {
          if(a[j][w ]==1)
          a[j][w]=0;
        }
    }
        cout<<"topological order:";
        for(int i=1;i<=n;i++)
         cout<<soln[i]<<" ";
         cout<<endl;
  }
  int topo::indegree(int node)
  { 
   int in_deg=0;
   for(int i=1;i<=n;i++)
   if(a[i][node]==1)
   in_deg++;
   return in_deg;
 }
 int main()
 { 
   topo top;
   top.readadj();
   top.toposort();
 }        
