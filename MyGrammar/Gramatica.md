#My Grammar

###Ideias Iniciais
    
    *Inserção de dados equivale a <<<
    *Saida de dados equivale a >>>
    *Operadores equivale a + - / * rest(resto da divisao)
    *variáveis equivale a...z e A..Z
    *String equivale a palavra->sua string aqui
    *atribuição de valores as variaveis equivale a x <- 2
    
###Gramática 

    <LinguagemE>::= <cmd> | <cmd>;<LinguagemE>
    <cmd>::= <leia> | <escreva> | <opecao> | <atribuicao> | <opercao> | <declaracao>
    <ler>::= <<< var   
    <escrever>::= >>> <texto>
    <texto>::= string | var | <texto> 
    <declaracao>::= <tipo><vars> | <tipo>var<atribuicao>
    <vars>::= var | var sep <vars> | var <atribuicao> sep <vars>
    <tipo>::= inteiro
    <expressao>::= num | <expressao><opercao><expressao> | PA<expressao>PF | var
    <operacao>::= soma | subtracao | divisao | multiplicacao | resto
    <atribuicao>::= var att <val>
    <val>::= num | var | <expr>
  
    
###Tokens
    

| Tokens        |     Padrão                                 | Atributo                                 |
|---------------|--------------------------------------------|------------------------------------------|
|  var          |[a-zA-Z]+(_)?[a-zA-Z0-9]*                   |  ID                                      |
| <<<           |  <<<                                       |                                          |
| >>>           |  >>>                                       |                                          |
| string        |palavra([\s\S]+ \|( )*[\s\S]* \| ( )*)      |                                          |
| sep           |       (,)                                  |                                          |
| inteiro       |  inteiro                                   |                                          |
| soma          |  +                                         |                                          |
| divisao       |  /                                         |                                          |
| subtração     |  -                                         |                                          |
| multiplicação |  *                                         |                                          |
| resto         | resto\([\w\d]*\,[\w\d]*\)                  |                                          |
| num           | (-)?(\d)+                                  |                                          |
| att           | <-                                         |                                          |


                                   
    

