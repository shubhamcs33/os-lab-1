#include <stdio.h>

int main()
{
    int n, i, j;
    printf("\nEnter the number of processes: ");
    scanf("%d",&n);
    int pid[n], at[i], bt[i], ct[n], wt[n], tat[n];
    for (i=0; i<n; i++)
    {
        printf("Process %d:\n", i+1);
        pid[i] = i+1;
        printf("Arrival Time: ");
        scanf("%d",&at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }
    for (i=0; i<n-1; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if (at[i] > at[j])
            {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }
    ct[0] = at[0] + bt[0];
    for (i=1; i<n; i++)
    {
        if (ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }
    for (i=0; i<n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    float avg_wt = 0, avg_tat = 0;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i=0; i<n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
        avg_wt = avg_wt + wt[i];
        avg_tat = avg_tat + tat[i];
    }
    printf("\nAverage Waiting Time: %f\n", avg_wt);
    printf("Average Turn Around Time: %f\n", avg_tat);
    return 0;
}
