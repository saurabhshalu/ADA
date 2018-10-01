#include <stdio.h>
#define N 100
typedef struct myItem
{
	char name;
	int profit;
	int weight;
	float value;
} ListItem;

int main()
{
	int i,j, n, op, W, t, temp;
	printf("Enter number of items: ");
	scanf("%d",&n);

	ListItem List[n];
	float taken[n];

	for(i=0;i<n;i++)
	{
		printf("Enter profit and weight of item %d: ", i+1);
		scanf("%d%d",&List[i].profit,&List[i].weight);
		List[i].value=(float)List[i].profit/(float)List[i].weight;
		taken[i]=0.0;
		List[i].name='A'+i;
	}

	for(i=0;i<n-1;i++)
	{
		t=i;
		ListItem te;
		for(j=i;j<n;j++)
			if(List[j].value>List[t].value)
				t=j;	
		te = List[i];
		List[i] = List[t];
		List[t] = te;
	}

	printf("Enter the Knapsack capacity: ");
	scanf("%d",&W);

	printf("\nChoose Method: \n1.Binary method\n2.Fraction method\nEnter (1 or 2): ");
	scanf("%d",&op);

	int count=0;
	temp=W;
	while(temp>0 && count<n)
	{
		if(temp>=List[count].weight)
		{
			temp-=List[count].weight;
			taken[count]=List[count].weight;
		}
		else
		{
			if(op==2)
			{
				taken[count]=temp;
				temp=0;
			}
		}
		count++;
	}
	

	printf("Item\tprofit\tweight\tselected\tearndProfit\n");
	float w, totProfit=0;
	for(i=0;i<n;i++)
	{
			float p;
			p = ((float)taken[i]==(float)List[i].weight)?List[i].profit:taken[i]*List[i].value;
			w+=taken[i];
			printf("Item %c\t%d\t%d\t%f\t%f\n",List[i].name,List[i].profit,List[i].weight,taken[i],p);
			totProfit+=p;
	}

	printf("Total Profit: %f\n",totProfit);
	printf("Remaining Space: %f\n", W-w);

	return 0;
}