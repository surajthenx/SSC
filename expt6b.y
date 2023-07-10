%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
extern int yylex();
extern FILE*yyin;
int id=0,dig=0,key=0,op=0;
%}
%name parse
%token DIGIT ID KEY OP
%%
input:input DIGIT {dig++;}
|input ID {id++;}
|input KEY{key++;}
|input OP{op++;}
|DIGIT {dig++;}
|ID {id++;}
|KEY {key++;}
|OP {op++;}
;
%%

int main(int argc,char*argv[])
{
 if(argc==2)
 {
 yyin=fopen(argv[1],"r");
 }
 else
 {
  printf("Input file missing\n");
  exit(0);
  }
  yyparse();
  
  printf("\n numbers=%d",dig);
  printf("\n keywords=%d",key);
  printf("\n identifiers=%d",id);
  printf("\n operators=%d",op);
  }
  
  int yyerror()
  {
   printf("EEK,parse error! Message;");
   exit(0);
   }
   int yywrap()
   {
    return 1;
    }
