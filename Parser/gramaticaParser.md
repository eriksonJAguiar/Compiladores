#Gramatica Para o Parser

<Expr>::= (<bool>)
<bool>::= <id> | <id> and <bool> | <id> or <bool>
<id>::= id | id <op> <id>
<op>::= < | <= | > | >= | == | !=

###Simplicação

A -> aBa
B-> C | CbB | CcB
C -> d | dDC
D-> f | fg | h | hg | gg | ig


#####1 Producao Vazia

Fecho-A {vazio}
Fecho-B {C}

A -> aBa
B-> d | dDC | CbB | CcB
C -> d | dDC
D -> f | fg | h | gg | ig

#####Chomsky

E1 -> aE2a
E2 -> d | dE4E3  E3bE2 | E3cE2
E3 -> d | dE4E3
E4 -> f | fg | h | gg | ig
E5 -> a
E6 -> b
E7 -> c
E8 -> d
E9 -> f
E10 -> g
E11 -> h
E12 -> i
