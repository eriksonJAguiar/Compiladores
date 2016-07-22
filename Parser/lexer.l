%{
  #include "tokens.h"
  int numline = 0;
%}
%%

[0-9A-Za-z]   return ID;
[(]           return ABREPRT;
[)]           return FECHAPRT;
(<|<=|>|>=|==|!=) return OP;
[\n]          numline++;
[ \t]                      ;
.             printf("Caracter Inesperado na linha %d",numline);

%%
int yyrwap(void) {
    return 1;
}
