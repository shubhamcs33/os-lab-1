#include <stdio.h>

typedef struct Process {
    int pid;
    int at;
    int bt;
    int remt;
    int ct;
    int tat;
    int wt;
    int completed;
} Process;

int main()
{
    Process p[20];
    int n, i;
    int time = 0, completed = 0;
    int min_remt, index;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Arrival Time for P%d: ", i + 1);
        p[i].pid = i + 1;
        scanf("%d", &p[i].at);

        printf("Burst Time for P%d: ", i + 1);
        scanf("%d", &p[i].bt);

        p[i].remt = p[i].bt;
        p[i].completed = 0;
    }

    while (completed < n)
    {
        min_remt = 9999;
        index = -1;

        for (i = 0; i < n; i++)
        {
            if (p[i].at <= time && p[i].completed == 0)
            {
                if (p[i].remt < min_remt && p[i].remt > 0)
                {
                    min_remt = p[i].remt;
                    index = i;
                }
            }
        }

        if (index == -1)
        {
            time++;
        }
        else
        {

            p[index].remt--;
            time++;

            if (p[index].remt == 0)
            {
                p[index].ct = time;
                p[index].tat = p[index].ct - p[index].at;
                p[index].wt = p[index].tat - p[index].bt;

                p[index].completed = 1;
                completed++;
            }
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++)
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




