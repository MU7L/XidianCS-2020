#include<stdio.h>
#include<math.h>
int a[10005];
typedef struct Data
{
	int address,key,Next,index;
}data;
data d[105];
int main()
{
	int n,head,headindex,sum=0;
	data temp;
	scanf("%d%d",&head,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&d[i].address,&d[i].key,&d[i].Next);
		a[abs(d[i].key)]=1; d[i].index=i;
		if(d[i].address==head) headindex=i;
	}
	for(int i=0;i<10005;i++)
	{
		sum+=a[i];
	}
	printf("%d\n",sum);
	temp=d[headindex];
	for(int i=0;i<n;i++)
	{
		if(a[abs(temp.key)]==1)
		{
			a[abs(temp.key)]++;
		}
		else if(a[abs(temp.key)]>1)
		{
			for(int j=0;j<n;j++)
			{
				if(d[j].address!=-1 && d[j].Next==temp.address)
				{
					d[j].Next=temp.Next;
					d[temp.index].address=-1;
					break;
				}
			}
		}
		for(int j=0;j<n;j++)
		{
			if(d[j].address==temp.Next)
			{
				temp=d[j];
				break;
			}
		}
	}
	temp=d[headindex];
	for(int i=0;i<sum;i++)
	{
		if(i<sum-1)
		{
			printf("%05d %d %05d\n",temp.address,temp.key,temp.Next);
		} 
		else printf("%05d %d -1\n",temp.address,temp.key);
		for(int j=0;j<n;j++)
		{
			if(d[j].address==temp.Next)
			{
				temp=d[j];
				break;
			}
		}
	}
	return 0;
}
