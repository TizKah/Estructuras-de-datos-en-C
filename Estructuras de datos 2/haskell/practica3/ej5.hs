{- 
    a) Defina una funcion parseRPN :: String → Exp que, dado un string que representa una expresion escrita en
    RPN, construya un elemento del tipo Exp presentado en el ejercicio 4 correspondiente a la expresion dada. Por
    ejemplo:
    parseRPN “8 5 3 − 3 ∗ +” = Add (Lit 8) (Prod (Sub (Lit 5) (Lit 3)) (Lit 3))
    Ayuda: para implementar parseRPN puede seguir un algoritmo similar al presentado anteriormente. En lugar
    de evaluar las expresiones, debe construir un valor de tipo Exp.
    
    b) Defina una funcion evalRPN :: String → Int para evaluar expresiones aritmeticas escritas en RPN. Por ejemplo:
    evalRPN “8 5 3 − 3 ∗ +” = 14
    Ayuda: use las funciones parseRPN y eval definidas anteriormente.
-}

data Exp = Lit Int | Add Exp Exp | Sub Exp Exp | Prod Exp Exp | Div Exp Exp

eval::Exp -> Int
eval (Lit num) = num
eval (Add n1 n2) = eval n1 + eval n2
eval (Sub n1 n2) = eval n1 - eval n2
eval (Prod n1 n2) = eval n1 * eval n2
eval (Div n1 n2) = div (eval n1) (eval n2)

-- Item a:
parseRPNAux::String -> [Exp] -> Exp 
parseRPNAux [] stack = head stack  
parseRPNAux (x : xs) (s1 : s2 : stack) 
                                | x == '+' = parseRPNAux xs ((Add s1 s2):stack)
                                | x == '-' = parseRPNAux xs ((Sub s2 s1):stack)
                                | x == '/' = parseRPNAux xs ((Div s2 s1):stack)
                                | x == '*' = parseRPNAux xs ((Prod s1 s2):stack)
                                | x == ' ' = parseRPNAux xs (s1:s2:stack)
                                | otherwise = parseRPNAux xs ((Lit (read [x])):s1:s2:stack)
parseRPNAux (x:xs) stack 
                        | x == ' ' = parseRPNAux xs stack
                        | otherwise = parseRPNAux xs ((Lit (read [x])):stack)                                

parseRPN::String -> Exp
parseRPN str = parseRPNAux str []

-- Item b:
evalRPN::String -> Int
evalRPN str = eval (parseRPN str)
