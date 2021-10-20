#include <stdio.h>
#include <stdlib.h>
struct pro{
    int at,bt,wt,tat,ct;
}process[50];

int burst[50],is_completed[50];
int i,n,in,mn,completed=0,current_time=0;
int tot_tat=0,tot_wt=0,tot_ct=0;

int main()
{   printf("Enter no of processes:\n");
    scanf("%d",&n);
    printf("Enter arrival time and burst time of\n");
    for(i=0;i<n;i++)
    {   printf("process %d:\n",i+1);
        scanf("%d%d",&process[i].at,&process[i].bt);
        burst[i]=process[i].bt;
        is_completed[i]=0;
    }
    while(completed!=n)
    {   in=-1;
        mn=10000000;
        for(i=0;i<n;i++)
        {   if(process[i].at<=current_time && is_completed[i]==0)
            {   if(burst[i]<mn)
                {   mn=burst[i];
                    in=i;
                }
                if(burst[i]==mn)
                {   if(process[i].at<process[in].at)
                    {   mn=burst[i];
                        in=i;
                    }
                }
            }
        }
        if(in!=-1)
        {   burst[in]-=1;
            current_time++;
            
            if(burst[in]==0)
            {   process[in].ct=current_time;
                process[in].tat=process[in].ct-process[in].at;
                process[in].wt=process[in].tat-process[in].bt;
                
                tot_ct+=process[in].ct;
                tot_wt+=process[in].wt;
                tot_tat+=process[in].tat;
                
                is_completed[in]=1;
                completed++;
            }
        }
        else
            current_time++;
    }
    printf("Average completion time = %.2f\n",(float)(tot_ct/n));
    printf("Average waiting time = %.2f\n",(float)(tot_wt/n));
    printf("Average turnaround time = %.2f\n",(float)(tot_tat/n));
    return 0;
}
