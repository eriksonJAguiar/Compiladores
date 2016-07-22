#Gramatica Para o Parser

<Expr>::= (<bool>)
<bool>::= <id> | <id> and <bool> | <id> or <bool>
<id>::= id | id <op> id
<op>::= < | <= | > | >= | == | !=

###Simplicação
