/*
1. Create filename.c file using given c program below
2. Create input.txt,optab.txt,symtab.txt files (all file contents are given below)
3. rum "cc filename.c"
4. type "./a.out"

*/
// Pass -1 of 2-pass assembler
 
#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
FILE *f1,*f2,*f3,*f4;
int lc,sa,l,op1,o,len;
char m1[20],la[20],op[20],otp[20];
clrscr();
f1=fopen("input.txt","r");
f3=fopen("symtab.txt","w");
fscanf(f1,"%s %s %d",la,m1,&op1);
if(strcmp(m1,"START")==0)
{
 sa=op1;
 lc=sa;
 printf("\t%s\t%s\t%d\n",la,m1,op1);
 }
 else
 lc=0;
fscanf(f1,"%s %s",la,m1);
while(!feof(f1))
{
 fscanf(f1,"%s",op);
 printf("\n%d\t%s\t%s\t%s\n",lc,la,m1,op);
 if(strcmp(la,"-")!=0)
 {
 fprintf(f3,"\n%d\t%s\n",lc,la);
 }
 f2=fopen("optab.txt","r");
 fscanf(f2,"%s %d",otp,&o);
 while(!feof(f2))
 {
  if(strcmp(m1,otp)==0)
  {
    lc=lc+3;
    break;
  }
  fscanf(f2,"%s %d",otp,&o);
  }
  fclose(f2);
  if(strcmp(m1,"WORD")==0)
 
    {
   lc=lc+3;
   }
   else if(strcmp(m1,"RESW")==0)
   {
    op1=atoi(op);
    lc=lc+(3*op1);
    }
    else if(strcmp(m1,"BYTE")==0)
    {
    if(op[0]=='X')
      lc=lc+1;
      else
      {
      len=strlen(op)-2;
      lc=lc+len;}
    }
    else if(strcmp(m1,"RESB")==0)
    {
     op1=atoi(op);
     lc=lc+op1;
     }
    fscanf(f1,"%s%s",la,m1);
    }
    if(strcmp(m1,"END")==0)
    {
    printf("Program length =\n%d",lc-sa);
    }
    fclose(f1);
    fclose(f3);
    getch();
    }
######################### input.txt ##########################

                    copy    START   1000
                            LDA     ALPHA
                            ADD     ONE
                            SUB     TWO
                            STA     BETA
                    ALPHA   BYTE    C'KLNCE
                    ONE     RESB    2
                    TWO     WORD    5
                    BETA    RESW    1
                    _       END     _
                    
######################### optab.txt ###########################

                    LDA     00
                    STA     23
                    ADD     01
                    SUB     05

######################### symtab.txt #########################


                    1000    LDA

                    1000    ONE

                    1003    STA

                    1003    BYTE

                    1003    RESB

                    1003    WORD

                    1003    RESW

                    1003    END

*/


