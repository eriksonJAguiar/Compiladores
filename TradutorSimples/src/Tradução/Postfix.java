package Tradução;

import java.io.IOException;


public class Postfix {
	public static void main(String agrs[]) throws IOException{
		
		//Lexer lex = new Lexer();
		
		Parser parse = new Parser();
		
		parse.expr(); 
		
		System.out.print("\n");
	}
}
