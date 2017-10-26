#include<iostream>
using namespace std;
const int MAX=10;
int visited[MAX];
class adjmatrix
{
  private:int a[MAX][MAX];
          int n;
  public: void readadj();
  	  void check();
  	  void dfs(int);
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
 void adjmatrix::check()
 {
      for(int i=1;i<=n;i++)
      {  
         if(visited[i]==0)
         { 
         cout<<"not connected\n";
         return;
         }
      }
      cout<<"connected";
 }
 void adjmatrix::dfs(int v)
 {
    visited[v]=1;
   for(int w=2;w<=n;w++)
   { 
   if((visited[w]==0) && (a[v][w]==1))
      { 
        dfs(w);
      }
    }
 }
 int main()
 { 
 adjmatrix g;
 g.readadj();
 g.dfs(1);
 g.check();
 return 0;
 }
   
