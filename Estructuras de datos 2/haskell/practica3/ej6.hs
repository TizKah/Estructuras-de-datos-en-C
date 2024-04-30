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


{- 

a) Considere el evaluador eval :: Exp → Int del ejercicio 4. ¿Como maneja los errores de division por 0?

b) Defina un evaluador seval :: Exp → Maybe Int para controlar los errores de division por 0.

-}

seval::Exp -> Maybe Int
seval (Lit num) = Just num
seval (Add n1 n2) = Just (eval n1 + eval n2)
seval (Sub n1 n2) = Just (eval n1 - eval n2)
seval (Prod n1 n2) = Just (eval n1 * eval n2)
seval (Div n1 (Lit n2)) = if n2 == 0 then (Nothing) else (Just (div (eval n1) n2))
seval (Div n1 n2) = Just (div (eval n1) (eval n2))