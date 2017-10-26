#include<iostream>
using namespace std;
const int infinity=999;
const int MAX=10;
class adjmatrix
{
  private: int a[MAX][MAX];
           int n;
           int d[MAX];
           int extract_min(int[]);
  public: void readadj();
          void dijsktras(int);
};
void adjmatrix::readadj()
{
  cout<<"enter the number of vertices"<<endl;
  cin>>n;
  cout<<"enter the adjcency matrix"<<endl;
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
    cin>>a[i][j];
}
 void adjmatrix::dijsktras(int s)
 {
   int visited[MAX];
   int u,v;
   int i;
   for(i=1;i<=n;i++)
   {
      visited[i]=0;
      d[i]=a[s][i];
   }
   visited[s]=1;
   d[s]=0;
   i=2;
   while(i<=n)
   {
     u=extract_min(visited);
     visited[u]=1;
     i++;
     for(v=1;v<=n;v++)
     {
     if(((d[u]+a[u][v])<d[v])&&(!
     visited[v]))
       d[v]=d[u]+a[u][v];
       }
   }
   for(i=1;i<=n;i++)
   {
     if(i!=s)
     cout<<i<<":"<<d[i]<<endl;
   }
 }
 int adjmatrix::extract_min(int visited[])
 {
   int i,j=1,min;
   min=infinity;
   for(i=1;i<=n;i++)
   {
     if((d[i]<min)&&(!visited[i]))
      {
        min=d[i];
        j=i;
       }
    }
    return j;
 }
 int main()
 {
   adjmatrix g1;
   g1.readadj();
   int s;
   cout<<"enter the start vertex"<<endl;
   cin>>s;
   g1.dijsktras(s);
 }
        
   
