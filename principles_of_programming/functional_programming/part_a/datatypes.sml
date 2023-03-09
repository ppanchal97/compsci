(* 
 Polymorphic data type that represents a Binary Tree data structure.
 This defines a new datatype called 'a tree, which is an algebraic data type that can represent a binary tree.
 The tree can either be Empty or it can be a Node with a value of type 'a, a left subtree of type 'a tree, and a right subtree of type 'a tree.
*)
datatype 'a tree = Empty
| Node of 'a * 'a tree * 'a tree

fun binary_tree_size t =
        case t of
            Empty => 0
        | Node (_, left, right) => 1 + binary_tree_size(left) + binary_tree_size(right)

(* Datatype to represent an expression *)
datatype expression = Constant of int
| Negate of expression
| Add of expression * expression
| Multiply of expression * expression

(* Pattern Matching Function to evaluate an expression *)
fun eval e = 
        case e of
            Constant i => i
        | Negate e2 => eval e2
        | Add(e1, e2) => eval e1 + eval e2
        | Multiply(e1, e2) => eval e1 * eval e2

(* Find the max constant of a given expression e.g., 2 + 3 * 10 *)
(* fun max_constant e = *)


(* Destructuring with pattern matching *)
fun sum_triple triple =
        let 
            val (x,y,z) = triple
        in
            x + y + z
        end

(* More elegant syntax with extracting variables out of the arguments using pattern matching *)
fun sum_triple (x,y,z) =
        x + y + z