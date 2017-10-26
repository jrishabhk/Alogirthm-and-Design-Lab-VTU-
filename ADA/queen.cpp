#include<iostream>
using namespace std;

#include<math.h>
#include<stdlib.h>
int const MAX=20;
int count;
void display(int i[],int);
void nqueens(int);
int place(int [],int);

int main()
    {
      int n;
      cout<<"enter the number of queens\n";
      cin>>n;
      nqueens(n);
      cout<<"the solution to the queens problem is:"<<count<<endl;
      return 0;
   }
  
void nqueens(int n)
   {
     int x[MAX];
     int k;
     x[0]=-1;
     k=0;
     while(k>=0)
        {
          x[k]=x[k]+1;
          while(x[k]<n && !place(x,k))
              x[k]=x[k]+1;
            if(x[k]<n)
               {
                 
                 if(k==n-1)
                { count++;
                 display(x,n);}
                 else
                   {
                     k++;
                     x[k]=-1;
                   }
                   }
                   else k--;
             }   
          }
          
int place(int x[],int k)
      {
         int i;
         for(i=0;i<k;i++)
            if((x[i]==x[k])||(abs(x[i]-x[k])==abs(i-k)))
                return 0;
                return 1;
      }
      

void display(int x[],int n)
      {
        char chessboard[MAX][MAX];
        int i,j;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
             chessboard[i][j]='X';
         for(i=0;i<n;i++)    
             chessboard[i][x[i]]='Q';
             for(i=0;i<n;i++)
                 {
                     for(j=0;j<n;j++)
                       cout<<chessboard[i][j]<<"  ";
                       cout<<"\n";
                  }
             cout<<"\n";
       }                                                             

