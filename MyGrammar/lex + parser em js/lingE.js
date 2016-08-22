var lexer = new Lexer();

lexer.addRule(/[0-9]+/,function(){
    return "NUMBER";
});

lexer.lex();
