void main()
{
  int n;int at[100];int at1[100];int bt[100];int bt1[100];int sum=0;int tat[100];int wt[100];float avg_wt=0.0;float avg_tat=0.0;int p[100];int p1[100];
  int s=0;
  printf("Enter the number of processes\n");
  scanf("%d",&n);
  for(int x=0;x<n;x++)
  {
      printf("Enter the arrival time of process %d \n",x+1);
      scanf("%d",&at[x]);
      at1[x]=at[x];
      printf("Enter the burst time of process %d \n",x+1);
      scanf("%d",&bt[x]);
      bt1[x]=bt[x];
      s=s+bt[x];
  }
  int start=0;int pos=-1;int min=bt1[0];
for(int x=0;x<s;x++)
{
    min=100;pos=-1;
        for(int y=0;y<n;y++)
        {
            if(at1[y]<=start&&bt1[y]<min)
            {
                min=bt1[y];
                pos=y;
            }
        }
        bt1[pos]=bt1[pos]-1;
        start++;
        if(bt1[pos]==0)
        {
            tat[pos]=start-at1[pos];
            bt1[pos]=100;
            wt[pos]=tat[pos]-bt[pos];
        }
}
printf("Process\t\tA.T.\tB.T.\tW.T\tT.A.T\n");
for(int x=0;x<n;x++)
{
 printf("P%d\t\t%d\t%d\t%d\t%d\n",x+1,at[x],bt[x],wt[x],tat[x]);
 avg_wt=avg_wt+wt[x];
 avg_tat=avg_tat+tat[x];
}
  avg_wt=avg_wt/n;
  avg_tat=avg_tat/n;
  printf("Average waiting time-%f\n",avg_wt);
  printf("Average turn-around time is-%f",avg_tat);
}
