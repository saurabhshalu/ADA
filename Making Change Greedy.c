#include <stdio.h>
int main()
{
	int i,j,n,num,t,temp,counter=0;
	printf("Enter number of coins: ");
	scanf("%d",&n);
	int d[n][2];
	printf("Enter %d denominations: ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&d[i][0]);
		d[i][1]=0;
	}
	for(i=0;i<n-1;i++)
	{
		t=i;
		for(j=i;j<n;j++)
			if(d[j][0]>d[t][0])
				t=j;	
		temp = d[i][0];
		d[i][0] = d[t][0];
		d[t][0] = temp;
	}
	printf("\nEnter amount: ");
	scanf("%d",&num);
	while(num>=d[n-1][0])
	{
		if(num>=d[counter][0])
		{
			num-=d[counter][0];
			d[counter][1]+=1;
		}
		else
			counter++;
	}
	printf("\n");
	for(i=0;i<n;i++)
		printf("Coin: %d, Count: %d\n", d[i][0], d[i][1]);
	printf("\nRemaining change is: %d", num);
	return 0;
}