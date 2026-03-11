#include <stdio.h>

struct Process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int completed;
};

int main()
{
    int n,i,time=0,done=0,index,min_bt;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct Process p[n];

    for(i=0;i<n;i++)
    {
        p[i].pid = i+1;

        printf("\nArrival Time for P%d: ",p[i].pid);
        scanf("%d",&p[i].at);

        printf("Burst Time for P%d: ",p[i].pid);
        scanf("%d",&p[i].bt);

        p[i].completed = 0;
    }

    while(done < n)
    {
        min_bt = 9999;
        index = -1;

        for(i=0;i<n;i++)
        {
            if(p[i].at <= time && p[i].completed == 0)
            {
                if(p[i].bt < min_bt)
                {
                    min_bt = p[i].bt;
                    index = i;
                }
            }
        }

        if(index == -1)
        {
            time++;
        }
        else
        {
            time += p[index].bt;
            p[index].ct = time;

            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;

            p[index].completed = 1;
            done++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid,
        p[i].at,
        p[i].bt,
        p[i].ct,
        p[i].tat,
        p[i].wt);
    }

    return 0;
}
