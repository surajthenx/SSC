%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int yylex();
int yyerror();
%}

%token  A  B
 
%%
str : S'\n' {printf("Valid string\n"); exit(0);} ;
S : A  S 
 | B 
  ;
%%
 
int main()
{
 printf("Enter the String:\n");
 yyparse();
}
  
int yyerror()
{
  printf("Inavalid String\n");
  exit(0);
}  
int yywrap()
{
  return 0;
}
