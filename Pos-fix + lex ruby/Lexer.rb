require_relative 'Token'
require_relative 'Tag'
class Lexer

  /Tag constantes numero e simbolo/
  $tag
  
 
 $expressao
 $peek 
 $token
 $pos 
 
 
 def initialize()
   $token = Token.new()
   $expressao = ""
   $pos = -1
   $peek = ' '
   $tag = Tag.new
 end
  
  
  def scan()
    t = Token.new
    
    $expressao = gets.chomp
    
    /elimina os espeços vazios/
    begin 
        $peek = getExp
        $pos+=1
        if ($peek != ' ' and $peek !='\t' and $peek != '\n')
          break
      end while ($expressao.length)
      
      if(isDigit($peek))
        
        puts("acessou")
        
      end
    end  
  end


   /verificar se peek é digito/
   def isDigit(valor)
      @@dig = 0..9
      @@dig.each do |i|
        if valor.eql?(i)
          retun true
        end
      end
        return false
    end
    
    
    /pegar dados da tela/
    def getExp
      if($pos == -1)
        $pos = 0
    elsif ($pos == integer($expressao.length))
      return 0
      end    
      return $expressao[$pos]   
    end  
   
   
end

