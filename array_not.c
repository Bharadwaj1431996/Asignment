*/4. Given an array of positive integers. The output should be the number of occurrences of each number.
Example:
Input: {2, 3, 2, 6, 1, 6, 2}
Output:
1 – 1
2 – 3
3 – 1
6 – 2*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct str
{
	int number;
	int count;
};
int numbernotpresent(struct str *ptr,int num,int n);
int main()
{
	int n;
	int l=0;
	scanf("%d",&n);
	int ind=0;
	int i=0;
	struct str *ptr=(struct str*)malloc(sizeof(struct str)*n);
	int *arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		l=numbernotpresent(ptr,arr[i],n);
		if(l==1)
		{
			(ptr+ind)->number=arr[i];
			(ptr+ind)->count+=1;
			ind++; 
		}
		else
		{
			(ptr+l)->count+=1;
		}
	}
	for(i=0;i<n;i++)
	{
		if((ptr+i)->number==0)
		{
			break;
		}
		printf("%d %d\n",(ptr+i)->number,(ptr+i)->count );
	}
	return 0;
}
int numbernotpresent(struct str *ptr,int num,int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		if((ptr+i)->number==0)
		{
			break;
		}
		if((ptr+i)->number==num)
		{
			return i;
		}
	}
	return 1;
}
