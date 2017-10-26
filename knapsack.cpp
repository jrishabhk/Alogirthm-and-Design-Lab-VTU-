 #include<iostream>
using namespace std;
const int MAX=30;
int V[MAX][MAX];
int keep[MAX][MAX];
int knapsack(int p[],int w[],int n,int M);
int main()
{
	int profits[MAX],i;
	int weights[MAX];
	int n,M,optsoln;
	cout<<"enter the no of items";
	cin>>n;
	cout<<"enter the weights:";
	for(i=1;i<=n;i++)
	cin>>weights[i];
	cout<<"enter the profits:";
	for(i=1;i<=n;i++)
	cin>>profits[i];
	cout<<"Knapsack value:";
	cin>>M;
	for(i=0;i<=M;i++)
	V[0][i]=0;
	for(i=0;i<=n;i++)
	V[i][0]=0;
	optsoln=knapsack(profits,weights,n,M);
	cout<<"soln="<<optsoln;
	return 0;
}
int knapsack(int p[],int w[],int n,int M)
{
	int r,i,j;
	for(i=1;i<=n;i++)
	for(j=0;j<=M;j++)
	if((w[i]<=j)&&(p[i]+V[i-1][j-w[i]])>V[i-1][j])
	{
		V[i][j]=p[i]+V[i-1][j-w[i]];
		keep[i][j]=1;
	}
	else
	{
		V[i][j]=V[i-1][j];
		keep[i][j]=0;
	}
	r=M;
	cout<<"items="<<endl;
	for(i=n;i>0;i--)
	if(keep[i][r]==1)
	{
		cout<<"\t"<<i<<"  ";
		r=r-w[i];
	}
	cout<<endl;
	return V[n][M];
}
