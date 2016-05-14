package Tradução;

import java.io.*;

import java.util.Scanner;

public class Parser {
	
	static int lookahead;	
	private String expressao;
	
	public Parser() throws IOException{
		
			lookahead = (char)System.in.read();	
	}
	
	void expr() throws IOException{
		
		term();
		
		while(true){
			if(lookahead == '+'){
				match('+'); term(); System.out.print("+"); expressao+='+';
			}
			else if(lookahead == '-'){
				match('-'); term(); System.out.print("-");expressao+='-';
			}
			else if(lookahead == '*'){
				match('*'); term(); System.out.print("*");expressao+='*';
			}
			else if(lookahead == '/'){
				match('/'); term(); System.out.print("/");expressao+='/';
			}
			else return;
		}
	}
	void term() throws IOException{
		if(Character.isDigit((char)lookahead)){
			System.out.print((char)lookahead); expressao+=((char)lookahead); match(lookahead);
			while(Character.isDigit((char)lookahead)){
				System.out.print((char)lookahead); expressao+=((char)lookahead); match(lookahead);
			}
		}
		else throw new Error("Sintax Error");
	}
	
	void match(int t) throws IOException{
		if(lookahead == t){ lookahead = System.in.read();}
		else throw new Error("Sintax Error");
	}
	
	
}
