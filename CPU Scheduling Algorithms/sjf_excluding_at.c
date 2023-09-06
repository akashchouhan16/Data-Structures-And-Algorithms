#include<stdio.h>
#include<stdlib.h>

void ta_time();
void wt_time();
void sjf();
char *a;
int bur_time[10],com_time[10],n,i,j;
	
void main()
{
	printf("How many processes you want:-\n");
	scanf("%d",&n);
	printf("Input %d Processes sequentially(without space):-\n",n);
	a=(char *)malloc(n*sizeof(char));
	scanf("%s",a);
	printf("\nInput corresponding burst time:-\n");
	for(i=0;i<n;i++)
	    scanf("%d",&bur_time[i]);
	sjf();
	ta_time();
	wt_time();
}
void ta_time()
{
	int bt=0;
	float avg=0.0;
    for(i=0;i<n;i++)
    {
    	bt=bt+bur_time[i]; // completion time
        com_time[i]=bt; // completion time - arrival time
	}
	printf("The Turnaround Time will be:-\n");
	for(i=0;i<n;i++)
	{
		printf("\n%c --> %d ",a[i],com_time[i]);
		avg=avg+com_time[i];
	}
	printf("\nHence, the average Turnaround Time will be:- %f ms",avg/n);
}
void wt_time()
{
	int wt=0;
	float avg=0.0;
    printf("\nThe Waiting Time will be:-\n");
	for(i=0;i<n;i++)
	{
		wt=com_time[i]-bur_time[i];
		printf("\n%c --> %d ",a[i],wt);
		avg=avg+wt;
	}
	printf("\nHence, the average Waiting Time will be:- %f ms4",avg/n);
}

void sjf()
{
    for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
            if(bur_time[j]>bur_time[j+1])
		    {
                int temp = bur_time[j];	
                bur_time[j] = bur_time[j+1];
                bur_time[j+1] = temp;
			}
		}
	}
}
