#include <cstdio>
#include <cctype>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

#define NUMBER 256
#define SYMBOL 257

using namespace std;

struct token{
    int type;
    double value;

    void print(){
        if (type == SYMBOL)
            printf("TOKEN {type: SYMBOL, value: %f}\n", value);
        else
            printf("TOKEN {type: NUMBER, value: %f}\n", value);
    }
};

string input;
int pos = -1;
char peek = ' ';
token lookahead;
std::vector<double> numeros;
std::vector<char> operadores;


//inputreader
int getchar(){
    if (pos == -1)
        pos = 0;
    else if (pos == (int) input.length())
        return 0;
    return input[pos++];
}

//lexer
token scan(){
    token t;
    for (;;peek=getchar()){
        if (peek != ' ' && peek != '\t' && peek != '\n')
            break;
    }
    if (isdigit(peek)){
        int v = 0;
        int cont = 0;
        int c = 0;
        do {
            	v = 10 * v + atoi(&peek);
            	peek = getchar();
        	}while (isdigit(peek));

        	numeros.push_back(v);

        if(peek == '.'){
        	do {
            	c = 10 * c + atoi(&peek);
            	peek = getchar();
            	cont++;
        	} while (isdigit(peek));

        	double decimal = c/(pow(10,cont-1));

        	double numero = v + decimal;

        	numeros.pop_back();

        	numeros.push_back(numero);

        	t.type = NUMBER;
        	t.value = numero;
        	return t;
       	}
        t.type = NUMBER;
        t.value = v;
        return t;
    }
    if(peek == '.'){
    	peek = getchar();
    	int v = 0;
    	int cont = 0;
        do {
            	v = 10 * v + atoi(&peek);
            	peek = getchar();
            	cont++;
        	}while (isdigit(peek));

        	double decimal = v / (pow(10,cont));

        t.type = NUMBER;
        t.value = decimal;
        return t;
    }
    if(peek == '/'){
    	peek = getchar();

    	if(peek == '*'){
    		bool AchouAsterisco = false;
    		bool AchouBarra = false;
    		do{
    			peek = getchar();

    			if(peek == '*')
    				AchouAsterisco = true;


    		}while(peek != '/' && AchouBarra != true);
    	}
    	else if(peek == '/'){
    		do{
    			peek = getchar();
    		}while(peek != '\n');
    	}
    }
    
    operadores.push_back(peek);
    
    t.type = SYMBOL;
    t.value = peek;
    peek = ' ';
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
    if (lookahead.type == NUMBER){
        printf("%f ", lookahead.value);
        match(lookahead);
    }else{
        printf("\n*** Syntax Error! '%f' it's not a number. ***\n", lookahead.value);
        exit(0);
    }
}

void expr(){
    term();
    while(true){
        if (lookahead.type == SYMBOL){
            if (lookahead.value == '+'){
                match(lookahead); term(); printf("+ ");
            }else if (lookahead.value == '-'){
                match(lookahead); term(); printf("- ");
            }else{
                return;
            }
        }else{
            return;
        }
    }
}

int main(){
    printf("Infix: ");
    getline(cin, input);

    printf("Postfix:");

    lookahead = scan();
    expr();

    printf("\n");
    return 0;
}
