#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
    FILE *f1, *f2, *f3;
    char mne[20], opnd[20], la[20];
    clrscr();
    f1 = fopen("minp2.txt", "r");
    f2 = fopen("ntab2.txt", "w+");
    f3 = fopen("dtab2.txt", "w+");
    fscanf(f1, "%s%s%s", la, mne, opnd);
    while (strcmp(mne, "MEND") != 0)
    {
        if (strcmp(mne, "MACRO") == 0)
        {
            fprintf(f2, "%s\n", la);
            fprintf(f3, "%s\t%s\n", la, opnd);
        }
        else
            fprintf(f3, "%s\t%s\n", mne, opnd);
        fscanf(f1, "%s%s%s", la, mne, opnd);
    }
    fprintf(f3, "%s", mne);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    printf("PASS 1 is successful");
    getch();
}


/*

################### Input file : ##################

minp2.txt

        EX1	MACRO	&A,&B
        -	LDA	&A
        -	STA	&B
        -	MEND	-
        SAMPLE	START	1000
        -	EX1	N1,N2
        N1	RESW	1
        N2	RESW	1
        -	END	-


################## Output files : ##################

dtab2.txt

        EX1	&A,&B
        LDA	&A
        STA	&B
        MEND


ntab2.txt

        EX1

*/