#My Grammar

###Ideias Iniciais
    
    *Inserção de dados equivale a <<<
    *Saida de dados equivale a >>>
    *Operadores equivale a + - / * rest(resto da divisao)
    *variáveis equivale a...z e A..Z
    *String equivale a palavra(sua string aqui)
    *atribuição de valores as variaveis equivale a x <- 2
    
###Gramática 

    <LinguagemE>::= <insercao>; | <saida>; | <declaracao>; | <operacaoes>; | <operacoesMat>;
    <ler>::= <<< <var>   
    <escrever>::= >>> <var> | >>> <string> | >>> <string>,<var>
    <operacoes>::= <var><atribuicao><var><op><var> | <var><atribuicao><num> | <var><atribuicao><var> | <resto> | <var><atribuicao><num> | <var><atribuicao><num><op><num> | <var><atribuicao><var><op><num> | <var><atribuicao><num><op><var> 
    <operacoesMat>::= <num><op><num><operacoesMat> | <var><op><var><operacoesMat> | &
    <op>::= + | - | * | /
    <atribuicao>::= <-
    <resto>::= rest(<num>,<num>)
    <num>::= <nums> | <nums><num>
    <nums>::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
    <tipo>::= inteiro 
    <declaracao>::= <tipo><var> | <tipo><var> <atribuicao> <num>
    <var>::= <letras> | <letras><num> | <letras>_<letras><num> | <letras><num>_<letras><num> | <letras><num>_<letras> 
    <letras>::= <letra> | <letra><letras>
    <letra>::= a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z 
    <string>::= palavra(<caracter>)
    <caracter>::= <stmt>
    <stmt>::= stmt | stmt<stmt>
    
    obs: & significa vazio
   
    
###Gramática na forma de Expressões Regulares

    ler ->  <<< id  
    escrever -> >>> id | >>> string | >>> string,id
    operadores -> (+|-|*|/) 
    atribuicao -> <-
    resto -> rest(num,num)
    num -> (-)?[0-9]+
    tipo -> inteiro 
    id ->  [a-zA-Z]+(_)?[a-zA-Z0-9]+
    letra -> [a-zA-Z]+
    string -> palavra(([a-zA-Z0-9] | ! | @ | $ | % | & | , | . | - | _ ))
    final -> ;
    
###Tokens
    

| Tokens      | Lexemas                     |     Padrão                                | Atributo                       |
|-------------|-----------------------------|-------------------------------------------|--------------------------------|
|   ler       |  <<<                        | Sequencia de <,<,<  (<<<)                 |                                |
| escrever    |  >>>                        | Sequencia de >,>,>  (>>>)                 |                                |
| operadores  |    *                        |        (*)                                |                                |
| operadores  |    +                        |        (+)                                |                                |
| operadores  |    -                        |        (-)                                |                                |
| operadores  |    /                        |        (/)                                |                                |
| atribuicao  |   <-                        |Sequencia de <,- (<-)                      |                                |
| resto       |resto(num,num)               |resto([0-9]+,[0-9]+)                       | palavra reservada              |
| tipo        |inteiro                      |      inteiro                              | palavra reservada              |
| id          |qualquer id                  | [a-zA-Z]+(_)?[a-zA-Z0-9]+                 |ponteiro para tabela de simbolos|
| num         |qualquer sequencia de digitos| [1-9][0-9]*                               |                                |
| letra       |a,b,C,D,E                    | [a-zA-Z]+                                 |                                | 
| string      |palavra(ola mundo)           | palavra(qualquer caracter da tabela ASCII)| palavra reservada              | 
|final        |;                            |  ( ; )                                    |                                | 
    

