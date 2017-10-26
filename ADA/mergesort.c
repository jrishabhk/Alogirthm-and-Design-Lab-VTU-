#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
const long MAX=10000;
void merge(int a[],int low,int mid,int high)
{	
	int b[MAX];
	int h,i,j,k;
	
	h=i=low;
	j=mid+1;
	
	while((i<=mid)&&(j<=high))
		{	
			if(a[i]<a[j])
				b[h++]=a[i++];
			else
				b[h++]=a[j++];
		}
	while(i<=mid){b[h++]=a[i++];}
	while(j<=high){b[h++]=a[j++];}
	for(k=0;k<=high;k++)
	 a[k]=b[k];
}
void mergesort(int a[],int low,int high)
{
	int mid;
	mid = (low + high)/2;
	
	if(low < high)
		{
			#pragma omp parallel
				{
					#pragma omp sections nowait
						{
							#pragma omp section
								{
									mergesort(a,low,mid);
								}
							#pragma omp section
								{
									mergesort(a,mid+1,high);
								}
	                	                                   
						
							
						}
						
			merge(a,low,mid,high);				
					  
				}
			 
		}
}
void main()
{
	int a[MAX];
	int i,j,n;
	clock_t start,stop;
	double duration;
	int icpu=omp_get_num_procs();
	
	srand((unsigned)time(NULL));
	omp_set_num_threads(icpu);
	
	printf("the number of threads %d\n",icpu);
	printf("parallel version of mergesort\n");
	for(n=0;n<MAX;n=n+1000)
	{
        
		for(i=0;i<n;i++)
		a[i]=rand();
		start=clock();
		for(i=0;i<100;i++)						
		mergesort(a,0,n-1);
		stop=clock();
	
	duration=(float)(stop-start)/CLOCKS_PER_SEC;
	printf(" %d \t %f\n",n,duration/100);
	}
}
