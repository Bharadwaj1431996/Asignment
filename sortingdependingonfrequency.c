#include<stdio.h>
#include<stdlib.h>
void sort(int arr[],int n);
int distinct(int arr[],int n);
int main()
{
	int i=0;
	int arr[]={2,2,3,2,3,4};
	int n=sizeof(arr)/sizeof(int);
	sort(arr,n);
	int j=0;
	int numberofdistinct=distinct(arr,n);
	int **dyn=(int**)malloc(sizeof(int*)*numberofdistinct);
	for(i=0;i<numberofdistinct;i++)
	{
		dyn[i]=(int*)malloc(sizeof(int)*2);
	}
	int count=0;
	int ind=0;
	int k=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]==arr[i+1] && (i+1<n))
		{
			dyn[ind][1]=++count;
		}
		else
		{
			dyn[ind][0]=arr[i];
			dyn[ind][1]=++count;
			ind++;
			count=0;
			k++;
		}
	}
	for(i=0;i<numberofdistinct;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d ",dyn[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int distinct(int arr[],int n)
{
	int i=0;
	int count=1;
	for(i=0;i<n;i++)
	{
		if((arr[i]!=arr[i+1]) && (i+1<n))
		{
			count++;
		}
	}
	return count;
}
void sort(int arr[],int n)
{
	int i=0;
	int j=0;
	int temp=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
