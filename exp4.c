#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	char gr[20],part1[20],part2[20],mod[20],new[20];
	int i,j=0,k=0,l=0,pos;
	printf("Enter production : A->");
	scanf("%s",gr);
	for(i=0;gr[i] != '|';i++,j++) {
		part1[j] = gr[i];
	}
	part1[j] = '\0';
	for(j=++i,i=0;gr[j] != '\0';j++,i++) {
		part2[i] = gr[j];
	}
	part2[j] = '\0';
        for (i = 0; part1[i] == part2[i]; i++) {
            mod[k++] = part1[i];
            pos = i + 1;
        }
        printf("\n A->%sX", mod);
        printf("\n X->%s|%s\n", &part1[pos],&part2[pos]);
	return 0;
}


----------------------------------OUTPUT---------------------
Enter production : A->aE+bcd|aE+a|T

 A->aE+X
 X->bcd|a|T

Enter production : A->bE+acF|bE+f

 A->bE+X
 X->acF|f
