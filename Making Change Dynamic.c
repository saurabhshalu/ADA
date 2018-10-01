#include <stdio.h>
int main()
{
	int i,j,n,num,t,temp,counter=0,flag=0;

	printf("\nEnter amount: ");
	scanf("%d",&num);

	printf("Enter number of coins: ");
	scanf("%d",&n);
	int d[n][2];
	printf("Enter %d denominations: ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&d[i][0]);
		d[i][1]=0;
		if(num%d[i][0]==0)
			flag=1;
	}
	if(flag==0)
		printf("Change is not possible in given denominations\n");
	else
	{
		int matrix[n+1][num+1];
		for(i=0;i<n-1;i++)
		{
			t=i;
			for(j=i;j<n;j++)
				if(d[j][0]<d[t][0])
					t=j;	
			temp = d[i][0];
			d[i][0] = d[t][0];
			d[t][0] = temp;
		}

		for(i=0;i<num+1;i++)
			matrix[0][i]=99;
		for(i=0;i<n+1;i++)
			matrix[i][0]=0;
		
		for(i=1;i<n+1;i++)
			for(j=1;j<num+1;j++)
			{
				if(i==1 && j<d[i-1][0])
					matrix[i][j]=99;
				else if(i==1)
					matrix[i][j]=1+matrix[i][j-d[i-1][0]];
				else if(j<d[i-1][0])
					matrix[i][j]=matrix[i-1][j];
				else
				{
					if(matrix[i-1][j]>=1+matrix[i][j-d[i-1][0]])
						matrix[i][j]=1+matrix[i][j-d[i-1][0]];
					else
						matrix[i][j]=matrix[i-1][j];
				}
			}
			
		i=n, j=num;
		while(i!=0 || j!=0)
		{
			if(matrix[i][j]==matrix[i-1][j])
				i--;
			else
			{
				j-=d[i-1][0];
				d[i-1][1]++;
			}
		}
		printf("\nCoin\tCount\n");
		for(i=0;i<n;i++)
			printf("%d\t%d\n", d[i][0], d[i][1]);
	}
	return 0;
}