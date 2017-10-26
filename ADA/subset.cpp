#include<iostream>
using namespace std;
const int MAX=10;
int s[MAX],soln[MAX];
int d;
void sumofsub(int,int,int);
int promising (int,int ,int);
 int main()
{
 int n,sum=0;
 cout<<"enter max.number:";
 cin>>n;
 cout<<"enter the set in increasing order:\n";
 for(int i=1;i<=n;i++)
 cin>>s[i];
 cout<<"enter the max.subset value(d): ";
 cin>>d;
 for(int i=1;i<=n;i++)
 sum=sum+s[i];
 if(sum < d || s[1] > d)
 cout<<"no subset possible\n";
 else
 sumofsub(0,0,sum);
 }
 void sumofsub(int i,int weight,int total)
 {
   if(promising(i,weight,total))
   if(weight == d)
   {
     for(int j=1;j<=i;j++)
     {
       if(soln[j])
       cout<<s[j]<<" ";
     }
     cout<< "\n";
    } 
     else
     {
       soln[i+1]=1;
       sumofsub(i+1,weight+s[i+1],total-s[i+1]);
       soln[i+1]=0;
       sumofsub(i+1,weight,total-s[i+1]);
     }
   }
     int promising(int i, int weight,int total)
     {
       return((weight+total >=d) && (weight==d || weight+s[i+1]<=d));
     } 

