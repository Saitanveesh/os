#include <stdio.h>

int main()
{
    int n, b[20], ch, p, t=0, sw=0, st=0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &b[i]);

    printf("1.FCFS 2.SJF: ");
    scanf("%d", &ch);

    puts("PID BT WT TAT");

    for(int k=0; k<n; k++)
    {
        p=-1;

        for(int i=0; i<n; i++)
        {
            if(b[i]==0) continue;
            if(p==-1) p=i;
            if(ch==2 && b[i]<b[p]) p=i;
        }

        printf("P%d %d %d %d\n", p+1, b[p], t, t+b[p]);
        sw+=t;
        t+=b[p];
        st+=t;
        b[p]=0;
    }

    printf("Average WT = %.2f\n", (float)sw/n);
    printf("Average TAT = %.2f\n", (float)st/n);
    return 0;
}
