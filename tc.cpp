#include<iostream>
using namespace std;
const int MAX=10;
 int i,j,k;
 class adjmatrix
 {
  private: int a[MAX][MAX];
           int n;
  public:void readadj();
         void printadj();
         void warshal();
 };
 void adjmatrix::readadj()
 {
   cout<<"enter the no of vertices"<<endl;
   cin>>n;
   cout<<"enter the adjmatrix"<<endl;
   for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   cin>>a[i][j];
 }
 void adjmatrix::printadj()
 {
    cout<<"transitive closure is"<<endl;
    for(i=1;i<=n;i++)
   {
   for(j=1;j<=n;j++)
    cout<<a[i][j]<<" ";
   cout<<endl;
   }
 }
 void adjmatrix::warshal()
 {
   for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);
 }
 int main()
 {
    adjmatrix g1;
    g1.readadj();
    g1.warshal();
    g1.printadj();
  return 0;
  }
