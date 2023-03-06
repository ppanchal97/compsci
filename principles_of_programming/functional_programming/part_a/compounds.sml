(* Pairs *)
val x = (1,2);

fun sort_pair (pr : int*int) =
        if (#1 pr) < (#2 pr)
        then pr
        else ((#2 pr),(#1 pr))


val y = sort_pair(x);

fun swap (pr : int*bool) =
        (#2 pr, #1 pr)

fun sum_two_pairs (pr1 : int*int, pr2 : int*int) =
        (#1 pr1) + (#2 pr1) + (#1 pr2) + (#2 pr2)

(* note: returning a pair is a real pain in Java *)
fun div_mod (x : int, y : int) = 
        (x div y, x mod y)


(* Lists *)
val l1 = [1,2,3,4,5];
(* 'Cons' prepends a value to a list*)
6::l1;

null l1; (* Evaluates to false as l1 != empty *)