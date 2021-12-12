#include <stdio.h>
// #include <conio.h>
int p[30], bt[30], tot_tat = 0, wt[30], n, tot_wt = 0, tat[30], SJF_wt = 0, SJF_tat = 0;
float awt, avg_tat, avg_wt;

int sort()
{
    int t, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                swap(&bt[j], &bt[i]);
                swap(&p[j], &p[i]);
            }
        }
    }
    return 0;
}

int swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
    return 0;
}

int WT_TAT(int *a, int *b)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            tat[i] = bt[i];
        else
            tat[i] = tat[i - 1] + bt[i];
        tot_tat = tot_tat + tat[i];
    }
    *a = tot_tat;
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tot_wt = tot_wt + wt[i];
    }
    *b = tot_wt;
    printf("\nPROCESS\t\tBURST TIME\tTURN AROUND TIME\tWAITING TIME");
    for (i = 0; i < n; i++)
        printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d", p[i] + 1, bt[i], tat[i], wt[i]);
    return 0;
}

void main()
{
    int i;
    clrscr();
    printf("\nEnter the no.of processes \n");
    scanf("%d", &n);
    printf("Enter burst time for each process\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        p[i] = i;
    }
    sort();
    WT_TAT(&SJF_tat, &SJF_wt);
    printf("\n\nTotal Turn around Time:%d", SJF_tat);
    printf("\nAverage Turn around Time :%d ", SJF_tat / n);
    printf("\nTotal Waiting Time:%d", SJF_wt);
    printf("\nTotal avg. Waiting Time:%d", SJF_wt / n);
    // getch();
}