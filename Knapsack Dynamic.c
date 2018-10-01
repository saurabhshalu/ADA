#include <stdio.h>
#define N 100
typedef struct myItem
{
	int profit;
	int weight;
} ListItem;
int main()
{
	int i,j, n, op, W, t, temp;
	printf("Enter number of items: ");
	scanf("%d",&n);

	int taken[n];
	ListItem List[n];

	for(i=0;i<n;i++)
	{
		printf("Enter profit and weight of item %d: ", i+1);
		scanf("%d%d",&List[i].profit,&List[i].weight);
		taken[i]=0;
	}

	printf("Enter the Knapsack capacity: ");
	scanf("%d",&W);

	int matrix[n+1][W+1];
	for(i=0;i<n+1;i++)
		matrix[i][0]=0;
	for(i=0;i<W+1;i++)
		matrix[0][i]=0;


	for(i=1;i<n+1;i++)
		for(j=1;j<W+1;j++)
		{
			if(j<List[i-1].weight)
				matrix[i][j]=matrix[i-1][j];
			else
			{
				if(matrix[i-1][j]>=List[i-1].profit+matrix[i-1][j-List[i-1].weight])
					matrix[i][j]=matrix[i-1][j];
				else
					matrix[i][j]=List[i-1].profit+matrix[i-1][j-List[i-1].weight];
			}
		}
	
	i--;
	j--;

	while(i>0)
	{
		if(matrix[i][j]==matrix[i-1][j])
			i--;
		else
		{
			taken[i-1]=i;
			j-=List[i-1].weight;
			i--;
		}
	}

	printf("Name\tprofit\tweight\n");
	for(i=0;i<n;i++)
		if(taken[i]!=0)
			printf("%c\t%d\t%d\n", 'A'+i,List[i].profit,List[i].weight);

	printf("\nTotal profit is %d",matrix[n][W]);

	return 0;
}