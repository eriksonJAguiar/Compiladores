%{
	int nline;

%}
%%
[a-zA-Z]+"_"?[a-zA-Z0-9]* printf("VAR");
[\n] {nline++;}
";" printf("Final");
"<<<" printf("read");
">>>" printf("write");
"palavra("[a-zA-Z]+[a-zA-Z ]*")" printf("string");
"," printf("sep");
"inteiro" printf("inteiro");
"+" printf("soma");
"-" printf("subtração");
"/" printf("divisao");
"*" printf("multiplicação");
"resto("[a-zA-Z0-9]+","[a-zA-Z0-9]+")" printf("resto");
"-"?[0-9][0-9]* printf("num");
"<-" printf("att");
%%
int main() {
    yylex();
    printf("Line %d\n",nline);
    return 0;
}
