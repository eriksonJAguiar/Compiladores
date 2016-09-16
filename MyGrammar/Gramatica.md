#My Grammar

###Ideias Iniciais

    *Inserção de dados equivale a <<<
    *Saida de dados equivale a >>>
    *Operadores equivale a + - / * resto(resto da divisao)
    *variáveis equivale a...z e A..Z
    *String equivale a palavra->sua string aqui
    *atribuição de valores as variaveis equivale a x <- 2

###Gramática

    <LinguagemE>::= <cmd>final | <cmd>final<LinguagemE> 
    <cmd>::= <leia> | <escreva> | <logico> | <declaracao>
    <ler>::= read var
    <logico>::= if<expressao> AC <cmd> FC 
    <escrever>::= write <texto>
    <texto>::= string | var 
    <declaracao>::= <tipo><vars> | <tipo>var<atribuicao>
    <vars>::= var | var sep <vars> | var <atribuicao> sep <vars>
    <tipo>::= inteiro
    <calc>::= var att <expressao> 
    <expressao>::=  num | <expressao><opercao><expressao> | pa<expressao>pf | var
    <operacao>::= soma | subtracao | divisao | multiplicacao | resto
    <atribuicao>::= var att <val>
    <val>::= num | var | <expressao>


###Tokens


| Tokens        |     Padrão                                 | Atributo                                 |
|---------------|--------------------------------------------|------------------------------------------|
|  var          |[a-zA-Z]+"_"?[a-zA-Z0-9]*                   |  ID                                      |
| read          |  "<<<"                                     |                                          |
| write         |  ">>>"                                     |                                          |
| string        |"palavra('.*?')"                            |   ponteiro para tabela de símbolos       |
| sep           |       ","                                  |                                          |
| inteiro       |  "inteiro"                                 |                                          |
| soma          |  "+"                                       |                                          |
| divisao       |  "/"                                       |                                          |
| subtração     |  "-"                                       |                                          |
| multiplicação |  "*"                                       |                                          |
| resto         | "resto("[a-zA-Z0-9]+","[a-zA-Z0-9]+")"     |                                          |
| num           | "-"?[1-9][0-9]*                            |                                          |
| att           | "<-"                                       |                                          |
| final         | ";"                                        |                                          |
| if            | "if"                                       |                                          |
| AC            | "{"                                        |                                          |
| FC            | "}"                                        |                                          |

