#My Grammar

###Ideias Iniciais

    *Inserção de dados equivale a <<<
    *Saida de dados equivale a >>>
    *Operadores equivale a + - / * rest(resto da divisao)
    *variáveis equivale a...z e A..Z
    *String equivale a palavra->sua string aqui
    *atribuição de valores as variaveis equivale a x <- 2

###Gramática

    <LinguagemE>::= <cmd> | <cmd>final<LinguagemE>
    <cmd>::= <leia> | <escreva> | <atribuicao> | <opercao> | <declaracao>
    <ler>::= read var   
    <escrever>::= write <texto>
    <texto>::= string | var | <texto>
    <declaracao>::= <tipo><vars> | <tipo>var<atribuicao>
    <vars>::= var | var sep <vars> | var <atribuicao> sep <vars>
    <tipo>::= inteiro
    <expressao>::= num | <expressao><opercao><expressao> | pa<expressao>pf | var
    <operacao>::= soma | subtracao | divisao | multiplicacao | resto
    <atribuicao>::= var att <val>
    <val>::= num | var | <expressao>


###Tokens


| Tokens        |     Padrão                                 | Atributo                                 |
|---------------|--------------------------------------------|------------------------------------------|
|  var          |[a-zA-Z]+"_"?[a-zA-Z0-9]*                   |  ID                                      |
| read          |  "<<<"                                     |                                          |
| write         |  ">>>"                                     |                                          |
| string        |"palavra("[a-zA-Z]+[a-zA-Z ]*")"            |   ponteiro para tabela de símbolos       |
| sep           |       ","                                  |                                          |
| inteiro       |  "inteiro"                                 |                                          |
| soma          |  "+"                                       |                                          |
| divisao       |  "/"                                       |                                          |
| subtração     |  "-"                                       |                                          |
| multiplicação |  "*"                                       |                                          |
| resto         | "resto("[a-zA-Z0-9]+","[a-zA-Z0-9]+")"     |                                          |
| num           | "-"?[0-9][0-9]*                            |                                          |
| att           | "<-"                                       |                                          |
| final         | ";"                                        |                                          |

###Parser
      LinguagemE>::= <cmd> | <cmd>final<LinguagemE>
      <cmd>::= <ler> | <escreva> | <operacao> | <atribuicao> | <declaracao>
      <ler>::= read var   
      <escrever>::= write <texto>
      <texto>::= string | var | <texto>
      <declaracao>::= <tipo><vars> | <tipo>var<atribuicao>
      <vars>::= var | var sep <vars> | var <atribuicao> sep <vars>
      <tipo>::= inteiro
      <expressao>::= num | <expressao><opercao><expressao> | pa<expressao>pf | var
      <operacao>::= soma | subtracao | divisao | multiplicacao | resto
      <atribuicao>::= var att <val>
      <val>::= num | var | <expressao>


####Simplificada

      <LinguagemE>::= read var | write <texto> | soma | subtracao | divisao | multiplicacao | resto | var att <val>  | <tipo><vars> | <tipo>var<atribuicao>| <cmd><final><LinguagemE>
      <cmd>::= read var | write <texto> | soma | subtracao | divisao | multiplicacao | resto | var att <val>  | <tipo><vars> | <tipo>var<atribuicao>
      <ler>::= read var   
      <escrever>::= write <texto>
      <texto>::= string | var
      <declaracao>::= <tipo><vars> | <tipo>var<atribuicao>
      <vars>::= var | var sep <vars> | var <atribuicao> sep <vars>
      <tipo>::= inteiro
      <expressao>::= num | <expressao><opercao><expressao> | PA<expressao>PF | var
      <operacao>::= soma | subtracao | divisao | multiplicacao | resto
      <atribuicao>::= var att <val>
      <val>::= num | var | <expressao><opercao><expressao> | PA<expressao>PF

####FNC
         
         <LinguagemE>::= <LinguagemEr><LinguagemEv> | <LinguagemEw><texto> | soma | subtracao | divisao | multiplicacao | resto | <LinguagemEaux> <val>  | <tipo><vars> | <LinguagemEaux2><atribuicao>|

          <cmd>::= <LinguagemEr><LinguagemEv> | <LinguagemEw><texto> | soma | subtracao | divisao | multiplicacao | resto | <LinguagemEaux> <val>  | <tipo><vars> | <LinguagemEaux2><atribuicao>|

          <ler>::= <LinguagemEr><LinguagemEv>   

          <escrever>::= <LinguagemEw><texto>

          <texto>::= string | var

          <declaracao>::= <tipo><vars> |  
          <LinguagemEaux2><atribuicao>

          <vars>::= var | <LinguagemEaux4><vars> | var <LinguagemEaux5><vars>  

          <tipo>::= inteiro

          <expressao>::= num | <LinguagemEaux7><expressao> | <LinguagemEaux8><LinguagemEauxpf> | var

          <operacao>::= soma | subtracao | divisao | multiplicacao | resto

          <atribuicao>::= <LinguagemEaux9><val>  

          <val>::= num | var | <LinguagemEaux10><expressao> |  <LinguagemEaux8><LinguagemEauxpf>
          <LinguagemEaux3><LinguagemE>

         <LinguagemEr>::= read

         <LinguagemEv>::= var

         <LinguagemEw>::= write

         <LinguagemEaux>::= <Lv><LinguagemEa>

         <LinguagemEa>::= att

         <LinguagemEaux2>::= <tipo><Lv>

         <LinguagemEaux3>::= <cmd><final>

         <LinguagemEaux4>::= <LinguagemEv><LinguagemEsep>

         <LinguagemEsep>::= sep

         <LinguagemEaux5>::= <LinguagemEaux6><LinguagemEsep>

         <LinguagemEaux6>::= <LinguagemEv><atribuicao>

         <LinguagemEaux7>::= <expressao><opercao>

         <LinguagemEaux8>::= <LinguagemEpa><expressao>

         <LinguagemEpa>::= pf

         <LinguagemEaux9>::= <LinguagemEv><LinguagemEa>

         <LinguagemEaux10>::= <expressao><opercao>

         <LinguagemEauxpf>::= pf

####FNG
             <LinguagemE>::= <LinguagemEr><LinguagemEv> | <LinguagemEw><texto> | soma | subtracao | divisao | multiplicacao | resto | <LinguagemEaux> <val>  | <tipo><vars> | <LinguagemEaux2><atribuicao>|

             <cmd>::= <LinguagemEr><LinguagemEv> | <LinguagemEw><texto> | soma | subtracao | divisao | multiplicacao | resto | <LinguagemEaux> <val>  | <tipo><vars> | <LinguagemEaux2><atribuicao>|

             <ler>::= <LinguagemEr><LinguagemEv>   

             <escrever>::= <LinguagemEw><texto>

             <texto>::= string | var

             <declaracao>::= <tipo><vars> | <LinguagemEaux2><atribuicao>

             <vars>::= var | <LinguagemEaux4><vars> | <LinguagemEaux5><vars>  

             <tipo>::= inteiro

             <expressao>::= num | <LinguagemEaux7><expressao> | <LinguagemEaux8><LinguagemEauxpf> | var

             <operacao>::= soma | subtracao | divisao | multiplicacao | resto

             <atribuicao>::= <LinguagemEaux9><val>  

             <val>::= num | var | <LinguagemEaux10><expressao> |  <LinguagemEaux8><LinguagemEauxpf>
             <LinguagemEaux3><LinguagemE>

            <LinguagemEr>::= read

            <LinguagemEv>::= var

            <LinguagemEw>::= write

            <LinguagemEaux>::= <Lv><LinguagemEa>

            <LinguagemEa>::= att

            <LinguagemEaux2>::= <tipo><Lv>

            <LinguagemEaux3>::= <cmd><final>

            <LinguagemEaux4>::= <LinguagemEv><LinguagemEsep>

            <LinguagemEsep>::= sep

            <LinguagemEaux5>::= <LinguagemEaux6><LinguagemEsep>

            <LinguagemEaux6>::= <LinguagemEv><atribuicao>

            <LinguagemEaux7>::= <expressao><opercao>

            <LinguagemEaux8>::= <LinguagemEpa><expressao>

            <LinguagemEpa>::= pf

            <LinguagemEaux9>::= <LinguagemEv><LinguagemEa>

            <LinguagemEaux10>::= <expressao><opercao>

            <LinguagemEauxpf>::= pf
