
{- 
a) Implementar las operaciones de este tipo algebraico teniendo en cuenta que:
 - Las funciones de acceso son headCL, tailCL, isEmptyCL, isCUnit.
 - headCL y tailCL no estan definidos para una lista vacıa.
 - headCL toma una CList y devuelve el primer elemento de la misma (el de mas a la izquierda).
 - tailCL toma una CList y devuelve la misma sin el primer elemento.
 - isEmptyCL aplicado a una CList devuelve True si la CList es vacıa (EmptyCL) o False en caso contrario.
 - isCUnit aplicado a una CList devuelve True sii la CList tiene un solo elemento (CUnit a) o False en caso
contrario.

b) Definir una funcion reverseCL que toma una CList y devuelve su inversa.

c) Definir una funcion inits que toma una CList y devuelve una CList con todos los posibles inicios de la CList.

d) Definir una funcion lasts que toma una CList y devuelve una CList con todas las posibles terminaciones de la
CList.

e) Definir una funcion concatCL que toma una CList de CList y devuelve la CList con todas ellas concatenadas


-}

data CList a = EmptyCL | CUnit a | Consnoc a (CList a) a


-- Item a:
headCL:: CList a -> a
headCL (CUnit elem) = elem
headCL (Consnoc elem _ _) = elem

tailCL:: CList a -> CList a
tailCL (CUnit elem) = EmptyCL
tailCL (Consnoc elem (Consnoc restListElem restList _) finalElem) = Consnoc restListElem restList finalElem

isEmptyCL:: CList a -> Bool
isEmptyCL EmptyCL = True
isEmptyCL _ = False

isCUnit:: CList a -> Bool
isCUnit (CUnit elem) = True
isCUnit _ = False


-- Item b:
reverseCL:: CList tipo -> CList tipo
reverseCL (EmptyCL) = EmptyCL
reverseCL (CUnit element) = CUnit element
reverseCL (Consnoc fstElement middleList lastElement) = Consnoc lastElement (reverseCL middleList) fstElement 

-- Item c:
-- c) Definir una funcion inits que toma una CList y devuelve una CList con todos los posibles inicios de la CList.
inits:: CList tipo -> CList tipo