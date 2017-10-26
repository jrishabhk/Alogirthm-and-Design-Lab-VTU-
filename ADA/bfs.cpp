#include<iostream>
using namespace std;
const int MAX=10;
int visited[MAX];
class adjmatrix
{
 private: int a[MAX][MAX];
          int q[MAX];
          int f,r;
          int n;
 public: void readadj();
         void bfs(int);
         void enqueue(int);
         int dequeue();
};
 void adjmatrix::readadj()
 { 
   cout<<"enter the no of vertices:";
   cin>>n;
   cout<<"enter the adjacency matrix:"<<endl;
   for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
   cin>>a[i][j];
 }
 void adjmatrix::bfs(int v)
 {
  int visit=0;
  f=0;
  r=-1;
  visited[v]=1;
  enqueue(v);
  while(f<=r)
  {
    v=dequeue();
    for(int w=1;w<=n;w++)
    {
      if(visited[w]==0 && a[v][w]==1)
      { 
         enqueue(w);
         visit++;
         cout<<w<<endl;
         visited[w]=1;
         }
    }
    if(visit==0)
    cout<<"no vertices visited\n";
    }
  }
  void adjmatrix::enqueue(int e)
  {
    q[++r]=e;
  }
  int adjmatrix::dequeue()
  { 
   int t=q[f];
   if(f==r)
   { 
    f=0;
    r=-1;
   }
   else
   f++;
   return t;
  }
  int main()
  {
    adjmatrix g;
    int s;
    g.readadj();
    cout<<"enter the starting vertex:";
    cin>>s;
    cout<<"visited vertex from "<<s<<" are\n";
    g.bfs(s);
    return 0;
   } 
  
         
    
