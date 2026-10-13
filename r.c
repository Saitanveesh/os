
#include <stdio.h>

int main()
{
    int n, at[20], bt[20], rem[20], ct[20], tat[20], wt[20];
    int order[20], q[25], front = 0, rear = 0;
    int time = 0, next = 0, completed = 0, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("P%d AT BT: ", i+1);
        scanf("%d%d", &at[i], &bt[i]);
        rem[i] = bt[i];
        order[i] = i;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(at[order[i]] > at[order[j]])
            {
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }

    while(completed < n)
    {
        if(front == rear && next < n && time < at[order[next]])
            time = at[order[next]];

        while(next < n && at[order[next]] <= time)
        {
            q[rear++ % 25] = order[next++];
        }

        int p = q[front++ % 25];
        int run = rem[p] < tq ? rem[p] : tq;

        time += run;
        rem[p] -= run;

        while(next < n && at[order[next]] <= time)
            q[rear++ % 25] = order[next++];

        if(rem[p] == 0)
        {
            ct[p] = time;
            completed++;
        }
        else
            q[rear++ % 25] = p;
    }

    printf("P\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
