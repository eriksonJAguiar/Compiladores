package lexer;

import java.io.IOException;
import java.util.Hashtable;

public class Lexer {
	public int line = 1;

	private char peek = ' ';
	
	private Tag tag;

	public Lexer() {
		tag = new Tag();
	}

	public Token scan() throws IOException {
		for (;; peek = (char) System.in.read()) {
			if (peek == ' ' || peek == '\t')
				continue;
			else if (peek == '\n')
				line += 1;
			else
				break;
		}
		if (Character.isDigit(peek)) {
				int v = 0;
				String aux = "";
				double p = 0;
				do {
					v = 10 * v + Character.digit(peek, 10);
					peek = (char) System.in.read();

				} while (Character.isDigit(peek));
				
				if(peek == '.'){
					
					peek = (char) System.in.read();
					
					int c = 0;
					
					do {
						c = 10 * c + Character.digit(peek, 10);
						peek = (char) System.in.read();

					} while (Character.isDigit(peek));
					
					
					
					p = Double.parseDouble(v+"."+c);
					
					Token t = new Token();
					
					t.type = tag.NUM;
					t.value = p;
					
					return t;
				}
				
				Token t = new Token();
				
				t.type = tag.NUM;
				t.value = v;
				
			return t;
		}
		// faz comentário desse tipo
		if (peek == '/') {
			peek = (char) System.in.read();
			boolean para;
			if (peek == '/') {
				do {
					peek = (char) System.in.read();

				} while (peek != '\n');
			}
			/* lê comentários desse tipo */
			else if (peek == '*') {
				do {
					para = false;

					peek = (char) System.in.read();

					if (peek == '*') {
						para = true;
						peek = (char) System.in.read();
					}

				} while (peek != '/' && para != true);

				peek = (char) System.in.read();
			}
		}
		Token t = new Token();
		t.type = tag.SYMBOL;
		t.value = peek;
		peek = ' ';
		return t;
	}
}
