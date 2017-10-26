#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<sys/time.h>
#define MAX 1000
double omp_floyd(int [MAX][MAX], int );
double seq_floyd(int [MAX][MAX], int );
int main()
{
	int a[MAX][MAX],c[MAX][MAX],i,j,n;
	double t_omp,t_seq,speedup;
	printf("Enter the no of vertices:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			a[i][j]=0;
			else
			a[i][j]=rand()%20;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=a[i][j];
		}
	}
	printf("Matrix is:");
	t_omp=omp_floyd(a,n);
	t_seq=seq_floyd(c,n);
	speedup=t_seq/t_omp;
	if(speedup<0)
	{
	 printf("\nSpeedup is for larger values\n");
	}
	printf("\n %lf & %lf ",t_omp,t_seq);
	printf("\nspeedup for parallel version=%0.2f%\n",speedup);
}
double omp_floyd(int a[MAX][MAX], int n)
{
	int i,j,k;
	double omp_start,omp_end,omp_time;
	double tick=omp_get_wtick();
	for(k=0;k<n;k++)
	{
		# pragma omp parallel shared (a,k) private (i,j)
		{
			omp_start=omp_get_wtime();
			# pragma omp for schedule(static)
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(a[i][k]+a[k][j]<a[i][j])
					{
						a[i][j]=a[i][k]+a[k][j];
					}
				}
			}
			omp_end=omp_get_wtime();
		}
	}
	omp_time=((omp_end-omp_start)/(tick*1000))*n;
	printf("%ld & tick=%lf ",omp_end,tick);
	printf("\nOpen mp version (time in period)=%f microseconds",omp_time);
	return omp_time;
}
double seq_floyd(int c[MAX][MAX], int n)
{
	int i,j,k;
	double seq_start,seq_end,seq_time;
	struct timeval t1,t2;
	gettimeofday(&t1,NULL);
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(c[i][k]+c[k][j]<c[i][j])
				{
					c[i][j]=c[i][k]+c[k][j];
				}
			}
		}
	}
	gettimeofday(&t2,NULL);
	printf("\n %lf ",t2.tv_usec);
	seq_time=(double)(t2.tv_usec-t1.tv_usec);
	printf("\nSequential version=%f",seq_time);
	return seq_time;
}
