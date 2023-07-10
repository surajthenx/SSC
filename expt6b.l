%{
#include<stdio.h>
#include"y.tab.h"
extern int yylval;
%}

%%
[\t];
[+|-|*|/|=|<|>]  {printf("operator is %s\n",yytext); return OP;}
[0-9]+ {return DIGIT;}
int |
char |
bool |
float |
void |
for |
do |
while |
if |
else |
return |
main  {printf("keyword is %s)n", yytext);  return KEY;}
[a-zA-Z][a-zA-Z0-9]* {printf("identifier is %s\n",yytext); return ID; }
.  ;
%%
