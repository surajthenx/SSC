%{
#include<stdio.h>
#include<string.h>
int flag=0,i=0,j,k=0;
char o[20][20],opar[20][20];
%}

%%
[0-9]+  {flag++; strcpy(o[i], yytext); i++;}
[+*/-]  {flag--;strcpy(opar[k],yytext);k++;}
. ;
%%

int main(int argc,char *argv[])
{
 printf("Enter an arithmetic expression\n");
 yylex();
 if(flag!=1)
 printf("Invalid Expression\n");
 else
 {
 printf("Valid Expression\n");
 printf("The Operands are\t");
 for(j=0;j<i;j++)
 printf("%s\t",o[j]);
 printf("\nThe operators are\t");
 for(j=0;j<k;j++)
 printf("%s\t",opar[j]);
 printf("\n");
 }
}
