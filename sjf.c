
#include <stdio.h>

int main()
{
    int n, at[20], bt[20], ct[20], tat[20], wt[20];
    int done[20] = {0}, time = 0, p;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("P%d AT BT: ", i+1);
        scanf("%d%d", &at[i], &bt[i]);
    }

    for(int k = 0; k < n; k++)
    {
        p = -1;

        for(int i = 0; i < n; i++)
            if(!done[i] && at[i] <= time)
                if(p == -1 || bt[i] < bt[p])
                    p = i;

        if(p == -1)
        {
            time++;
            k--;
            continue;
        }

        time += bt[p];
        ct[p] = time;
        done[p] = 1;
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
