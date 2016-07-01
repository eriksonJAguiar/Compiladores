%{
  #include<stdio.h>

  int nline;

%}
%%
"inteiro" printf("INTEIRO");
[a-zA-Z]+"_"?[a-zA-Z0-9]* printf("VAR %s",yytext);
[\n] nline++;
";" printf("FINAL");
"<<<" printf("READ");
">>>" printf("WRITE");
"palavra("[a-zA-Z]+[a-zA-Z ]*")" printf("STRING %s",yytext);
"," printf("SEP");
"+" printf("SOMA");
"-" printf("SUBTRACACAO");
"/" printf("DIVISAO");
"*" printf("MULTIPLICACAO");
"resto("[a-zA-Z0-9]+","[a-zA-Z0-9]+")" printf("RESTO");
"-"?[0-9][0-9]* printf("NUM %s",yytext);
"<-" printf("ATT");
. printf("Caracter Inesperado na linha %d",nline);
%%
int main() {
    yylex();
    printf("Line %d\n",nline);
    return 0;
}
