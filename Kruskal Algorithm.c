#include<stdio.h>
#define N 100
typedef struct myEdge
{
    int x;
    int y;
    int w;
    int used;
} edge;
typedef struct myEdgeList
{
    edge data[N];
    int num;
} edgeList;
edgeList sortlist(edgeList l)
{
    edge temp;
    int i,j,t;
    for(i=0;i<l.num-1;i++)
    {
        t=i;
        for(j=i;j<l.num;j++)
            if(l.data[j].w<l.data[t].w)
                t=j;

            temp = l.data[i];
            l.data[i] = l.data[t];
            l.data[t] = temp;
    }
    return l;
}

int magicArray[N];

int main()
{
    int n,i,j,a,b;
    edgeList eL;
    eL.num=0;

    printf("Enter number of nodes : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
        magicArray[i]=i;

    int matrix[n][n];

    printf("Enter Matrix (NxN):\n");
    for(i=0;i<n;i++)
        for(j=0;j<=i;j++)
        {
            if(i==j)
                matrix[i][i]=0;
            else
            {
                printf("Enter distance between %d and %d ",i,j);
                scanf("%d",&matrix[i][j]);
                matrix[j][i]=matrix[i][j];
                eL.data[eL.num].x=i;
                eL.data[eL.num].y=j;
                eL.data[eL.num].w=matrix[i][j];
                eL.num++;
            }
        }

    eL=sortlist(eL);

    for(i=0;i<eL.num;i++)
    {
        a = magicArray[eL.data[i].x];
        b = magicArray[eL.data[i].y];

        if(a!=b)
        {
            eL.data[i].used = 1;
            for(j=0;j<n;j++)
                if(magicArray[j]==b)
                    magicArray[j]=a;
        }

    }
    
    printf("\nRESULT\n");
    for(i=0;i<eL.num;i++)
        if(eL.data[i].used==1)
            printf("(%d, %d) = %d\n",eL.data[i].x,eL.data[i].y,eL.data[i].w);  
}