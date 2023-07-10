%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stk[20],input[20];
int top=-1;
int i=0;
%}

%name parse
%token id
%left '+'   '-'
%left '*'   '/'
%left '('   ')'
%%
L:E {printf("Accept\n");}
;
E:E '+' T{stk[top-2]='E';top=top-2;stk[top+1]='\0';printf("%s\t%s\t",stk,&input[i]);
printf("Reduce E->E+T\n");}
|T
{stk[top-1]='E'; printf("%s\t%s\t",stk,&input[i]);
printf("Reduce E->T\n");}
;
T:T  '*' F  {stk[top-3]='T'; top=top-3;stk[top+1]='\0';printf("%s\t%s\t",stk,&input[i]);
printf("Reduce T->T*F\n");}
|F
{stk[top-1]='T'; stk[top+1]='\0';printf("%s\t%s\t",stk,&input[i]);
 printf("Reduce T->F\n");}
 ;
 F:id
 {stk[top-1]='F'; stk[top+1]='\0'; printf("%s\t%s\t",stk,&input[i]);
 printf("Reduce F->id\n");}
 ;
 %%
 
main()
 {
 stk[++top]='$';
 printf("Grammar is:\n");
 printf("E->E+T|T\n T*F|F\n F->ID\n");
 printf("Enter the Expression\n");
 scanf("%s",input);
 printf("stack\tInput\tAction\n");
 yyparse();
 return 0;
 }
 yylex()
 {
  while(input[i]!='\0')
  {
  if(input[i]=='i'&&input[i+1]=='d')
  {
  stk[++top]='i';
  stk[++top]='d';
  stk[top+1]='\0';
  i=i+2;
  printf("%s\t%s\t%s\n",stk,&input[i],"Shift ID");
  return id;
  }
  else
  {
  stk[top]=input[i];
  stk[top+1]='\0';
  i=i+1;
  printf("%s\t%s\t%s\n",stk,&input[i],"Shift Symbol");
  return input[i-1];
  }
  }
  }
  yyerror()
  {
  printf("Invalid Expression\n");
  exit(1);
  }

