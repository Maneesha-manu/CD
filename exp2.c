#include<stdio.h>
#include<string.h>
#define SIZE 10
int main()
{
char nt;
char a,b;
int num;
int i;
char p[10][SIZE];
int index=3;
printf("Enter no:of production:");
scanf("%d",&num);
printf("Enter the grammer as E-->E-A: \n");
for(i<0;i<num;i++)
scanf("%s",p[i]);
for(i=0;i<num;i++)
{
printf("\nGrammer::: %s",p[i]);
nt=p[i][0];
if(nt=p[i][index])
{
b=p[i][index+1];
printf(" is left recursive:\n");
while(p[i][index]!=0 && p[i][index]!='|')
{
index++;
}
if(p[i][index]!=0)
{
b=p[i][index+1];
printf("Grammer without left Recursive\n");
printf("%c->%c%c'\n",nt,b,nt);
printf("\n%c\'->%c%c\'|E\n",nt,b,nt);
}
else
printf(" can't be Reduced\n");
}
else
printf(" is not left Recursion\n");
index=3;
}
}


------------OUTPUT--------------------
Enter no:of production:3
Enter the grammer as E-->E-A: 
E->EA|A
A->a
E->i

Grammer::: E->EA|A is left recursive:
Grammer without left Recursive
E->AE'

E'->AE'|E

Grammer::: A->a is left recursive:
 can't be Reduced

Grammer::: E->i is left recursive:
 can't be Reduced


Enter no:of production:4
Enter the grammer as E-->E-A: 
E->EA|A
E->AT|a
T->a
E->i

Grammer::: E->EA|A is left recursive:
Grammer without left Recursive
E->AE'

E'->AE'|E

Grammer::: E->AT|a is left recursive:
Grammer without left Recursive
A->aA'

A'->aA'|E

Grammer::: T->a is left recursive:
 can't be Reduced

Grammer::: E->i is left recursive:
 can't be Reduced








