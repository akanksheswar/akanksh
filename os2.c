#include<stdio.h>
int main()
{
	int i;
	int a[10],gifts[10],atime[10];
	printf("\nlets get started");
	for(i=0;i<10;i++)
	{
		printf("\nenter details of %d",i+1);
		a[i]=i;
		printf("\nenter no of gifts");
		scanf("%d",&gifts[i]);
		printf("enter arrival time ");
		scanf("%d",&atime[i]);
		printf("\n");
	}
	printf("\nsorting data according gifts");
	int temp,j;
	for(i=0;i<10;i++)
	{
		for(j=i;j<10;j++)
		{
			if(atime[i]>=atime[j])
			{
				if(atime[i]==atime[j])
				{
					if(gifts[i]<gifts[j])
					{
						temp=atime[i];
						atime[i]=atime[j];
						atime[j]=temp;
					
						temp=gifts[i];
						gifts[i]=gifts[j];
						gifts[j]=temp;
				
						temp=a[i];
						a[i]=a[j];
						a[j]=temp;
					}
				}
			
			}
		}
	}
	printf("\nstudent\tgifts\tarrvial time");
	for(i=0;i<10;i++)
	{
		printf("\n%d\t\t%d\t\t%d",a[i],gifts[i],atime[i]);
	}
	printf("\norder of billing");
	for(i=0;i<10;i++)
	{
		printf("\n%d",a[i]);
	}
	return 0;
}
