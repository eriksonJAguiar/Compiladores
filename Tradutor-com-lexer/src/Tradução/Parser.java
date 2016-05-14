package Tradução;

import java.io.*;

import java.util.Scanner;

import lexer.*;

public class Parser {
	
	public Token lookahead;	
	private String expressao;
	private Lexer lex;
	private Tag tag;
	
	public Parser() throws IOException{
		lex = new Lexer();	
		tag = new Tag();
		lookahead = lex.scan();
	}
	
	void expr() throws IOException{
		term();
		while(true){
	        if (lookahead.type == tag.SYMBOL){
	            if (lookahead.value == '('){
	                match(lookahead); 
	            }
	            else if (lookahead.value == ')'){
	                match(lookahead); 
	            }
	            else if (lookahead.value == '/'){
	                match(lookahead); term(); System.out.print("/");
	            }
	            else if (lookahead.value == '*'){
	                match(lookahead); term(); System.out.print("*");
	            }
	            else if (lookahead.value == '+'){
	                match(lookahead); term(); System.out.print("+");
	            }
	            else if (lookahead.value == '-'){
	                match(lookahead); term(); System.out.print("-");
	            }
	            else{
	                return;
	            }
	        }else{
	            return;
	        }
		}
	
	}
	void term() throws IOException{
		if(lookahead.type == tag.NUM){
			System.out.print(lookahead.value);
			match(lookahead);
		}
		else throw new Error("Syntax Error");
	}
	
	void match(Token t) throws IOException{
		if(lookahead.type == t.type && lookahead.value == t.value){ lookahead = lex.scan(); }
		else throw new Error("Sintax Error");
	}
	
	
}
