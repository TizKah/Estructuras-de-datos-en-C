-- TP hecho en grupo de tres integrantes.

{-# LANGUAGE MultiParamTypeClasses #-}
{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
-- t = Node 'r' Nothing E (Node 'e' (Just 16) (Node 'a' Nothing E (Leaf 's' 1) E) (Node 'o' (Just 2) (Leaf 'd' 9) E  (Leaf 's' 4)) E) (Node 's' Nothing E (Node 'i' (Just 4) (Leaf 'e' 8) (Leaf 'n' 7) E) E)

data TTree k v = Node k (Maybe v) (TTree k v) (TTree k v) (TTree k v)
                | Leaf k v
                | E

class Dic k v d | d -> k v where
    vacio       :: d
    insertar    :: Ord k => k -> v -> d -> d
    buscar      :: Ord k => k -> d -> Maybe v 
    eliminar    :: Ord k => k -> d -> d
    claves      :: Ord k => d -> [k]


instance (Ord k, Eq v) => Dic [k] v (TTree k v) where
    vacio = E
    insertar = insert
    buscar = search
    eliminar = delete
    claves = keys

search :: Ord k => [k] -> TTree k v -> Maybe v
search (kl:kls) (Leaf k v)
    | kl == k && null kls = (Just v)        -- Elemento encontrado
    | otherwise = Nothing                   -- No se encontró
search (kl:kls) (Node k v tree_l child tree_r)
    | kl == k && null kls = v               -- Elemento encontrado
    | kl == k = search kls child            -- Seguimos en el child
    | kl < k = search (kl:kls) tree_l       -- Seguimos en el hermano izquierdo
    | kl > k = search (kl:kls) tree_r       -- Seguimos en el hermano izquierdo
    | otherwise = Nothing                   -- No se encontró
search _ _ = Nothing



insert :: Ord k => [k] -> v -> TTree k v -> TTree k v
insert [] value tree = tree
insert (s:str) value (Leaf k v)
    -- Caso borde que se ingresa un único char que es igual al de la hoja:
    | str == [] && s == k = (Leaf k value)

    -- El primer elemento de la key del user es igual a la k de la hoja:
    | s == k = (Node k (Just v) E (insert str value E) E) 

    -- En vez de hijos, haces de hermano:
    | s < k = (Node k (Just v) (insert (s:str) value E) E E)
    | s > k = (Node k (Just v) E E (insert (s:str) value E))
    
insert (s:str) value E
        | str == [] = (Leaf s value)                                  -- Insertamos el value
        | otherwise = (Node s Nothing E (insert str value E) E)       -- Insertamos en el hijo recursivamente las keys

insert (s:str) value tree@(Node key val l child r)
        -- Caso sobreescribir el value. La key completa ya existía:
        | s == key && str == [] = (Node key (Just value) l child r)

        -- Caso que la s que estamos leyendo es parte de otro prefijo:
        | s == key = if (s_min_k_subarbol str child)
                    then (Node key val l (insert str value child) r)
                    else if (tree_keyE s l)
                            then (Node s val (insert (s:str) value l) child r)
                            else (Node s val l child (insert (s:str) value r)) 

        -- Caso que debamos meter el value entre dos hermanos:
        | s < key && (tree_keyE s l) && str == [] = (Node s (Just value) l E E)
        | s > key && not (tree_keyE s r) && str == [] = (Node s (Just value) E E r)

        -- Caso debemos pasar al hermano izquierdo o derecho:
        | s < key = (Node key val (insert (s:str) value l) child r) -- Hay que insertarlo en el subárbol izquierdo
        | s > key = (Node key val l child (insert (s:str) value r)) -- Hay que insertarlo en el subárbol derecho




treeEmpty :: TTree k v -> Bool
treeEmpty E = True
treeEmpty _ = False

delete :: Ord k => [k] -> TTree k v -> TTree k v
delete [] E = E
delete (s:str) (Leaf k v)
    | str == [] && k == s = E
    | otherwise = (Leaf k v)
delete (s:str) (Node k v tree_l child tree_r)
    | str == [] && s == k = if ((treeEmpty tree_l) && (treeEmpty tree_r) && (treeEmpty child))
                                then (E)
                                else (Node k Nothing tree_l child tree_r)
    | s == k && null v = if ((treeEmpty res) && (treeEmpty tree_l) && (treeEmpty tree_r))
                                then E
                                else (Node k v tree_l res tree_r)
    | s == k = (Node k v tree_l (delete str child) tree_r)
    | s < k && (treeEmpty tree_l) = (Node k v tree_l child tree_r)
    | s > k && (treeEmpty tree_r) = (Node k v tree_l child tree_r)
    | s < k = (Node k v (delete (s:str) tree_l) child tree_r)
    | s > k = (Node k v tree_l child (delete (s:str) tree_r))
    where 
      res = delete str child

keys :: Eq v => TTree k v -> [[k]]
keys (Node k v tree_l child tree_r)
    | v == Nothing = (keys tree_l) ++ (append k (keys child)) ++ (keys tree_r)
    | otherwise = (keys tree_l) ++ [[k]] ++ (append k (keys child)) ++ (keys tree_r)
keys (Leaf k v) = [[k]]
keys E = []



-- Funciones auxiliares:
append :: k -> [[k]] -> [[k]]
append s (k1:ks) = [(s:k1)] ++ (append s ks)
append _ _ = []

tree_keyE:: Ord k => k -> TTree k v -> Bool
tree_keyE a E = False
tree_keyE a (Leaf k v) = a < k
tree_keyE a (Node k v _ _ _) = a < k

s_min_k_subarbol ::Ord k => [k] -> TTree k v -> Bool
s_min_k_subarbol (a:as) E = False
s_min_k_subarbol (a:as) (Leaf k v) = a == k
s_min_k_subarbol (a:as) (Node k v l child r) = (a == k) || (s_min_k_subarbol [a] l) || (s_min_k_subarbol [a] r)