#include <stdio.h>
#include <stdlib.h>

int main()
{
    int RQ[100], i, n, TotalHeadMoment = 0, initial, sum = 0, h;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);

    printf("%d", initial);
    for (i = 0; i < n; i++)
    {
        printf(" -> %d", RQ[i]);

        // logic for FCFS disk scheduling
        TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
        initial = RQ[i];
    }
    printf("\nTotal head movements = %d \n", TotalHeadMoment);
    return 0;
}