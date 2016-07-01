%{
  #include "token.h"
    int nline=1;
    int operacacao;
%}
%%
[0-9][0-9]*         return NUMERO;
\+                 {operacacao = ADI;return SIMBOLO;}
\*                  {operacacao = MULT;return SIMBOLO;}
\/                  {operacacao = DIV;return SIMBOLO;}
\-                  {operacacao = SUB;return SIMBOLO;}
[ \t$]                 ;
[\n]                  nline++;
. printf("Erro Caracter inesperado na linha %d\n",nline);

%%
int yywrap(void)
{
	return 1;
}
