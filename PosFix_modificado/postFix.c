#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include "token.h"



typedef struct token{
    int type;
    char* value;
}token;


token lookahead;
char auxOp;

extern int yylex();
extern int operacacao;
extern int nline;
extern char* yytext;
extern FILE *yyin;
extern char* yyval;

FILE *entrada;

//lexer
void readFile(){
  entrada = fopen("file.fix","r");
  yyin = entrada;
}

token scan(){
    token t;

    t.type = yylex();
    t.value = yytext;

    return t;
}

//parser
void match(token t){
    if (lookahead.type == t.type && lookahead.value == t.value){
        lookahead = scan();
    }else{
        printf("\n*** Syntax Error! Values do not match. *** \n");
        exit(0);
    }
}

void term(){

    if (lookahead.type == 2){
        printf("%s ", lookahead.value);
        match(lookahead);
    }else{
        printf("\n*** Syntax Error! '%s' it's not a number. ***\n", lookahead.value);
        exit(0);
    }
}

void expr(){
    term();
    while(1){
        if (lookahead.type == 1){
            if (operacacao == 11){
                match(lookahead);
                term();
                printf("+ ");
            }else if (operacacao == 12){
                match(lookahead);
                term();
                printf("- ");

            }else if (operacacao == 13){
                match(lookahead);
                term();
                printf("* ");

            }else if (operacacao == 14){
                match(lookahead);
                term();
                printf("/ ");

            }
          }/*else if(lookahead.type == 3){

          }*/else{
            return;
          }
    }
}

int main(){
    printf("Lendo Infix...\n");
    sleep(1);
    readFile();

    printf("Postfix:");
    lookahead = scan();
		expr();
    printf("\n");

    fclose(entrada);


    return 0;
}
