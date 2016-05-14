package lexer;

public class Symbol extends Token{
	
	public final int value;
	
	public Symbol(int v) { super(Tag.SYMBOL); value = v; }
	
}
