#include<stdio.h>
#include<stdlib.h>
#include "lex.yy.c"


int main(){

  int ntoken, cline;
  cline = nline;
  yyin = fopen("file.E","r");
  ntoken = yylex();
  while(ntoken) {
    if(ntoken == INTEIRO)
      printf("<INTEIRO>");
    else if(ntoken == VAR)
      printf("<VAR,%s>",yytext);
    else if(ntoken == READ)
      printf("<READ>");
    else if(ntoken == WRITE)
      printf("<WRITE>");
    else if(ntoken == STRING)
      printf("<STRING,%s>",yytext);
    else if(ntoken == SEP)
      printf("<SEP>");
    else if(ntoken == SOMA)
      printf("<SOMA>");
    else if(ntoken == SUB)
      printf("<SUB>");
    else if(ntoken == DIV)
      printf("<DIV>");
    else if(ntoken == MULT)
      printf("<MULT>");
    else if(ntoken == RESTO)
      printf("<RESTO>");
    else if(ntoken == NUM)
      printf("<NUM,%s>",yytext);
    else if(ntoken == ATT)
        printf("<ATT>");
    else if(ntoken == FINAL)
            printf("<FINAL>\n");


    ntoken = yylex();
  }
    fclose(yyin);
  printf("\n EOF - Lines: %d\n", nline);

}
