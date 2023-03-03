(* 
    if l1 = [1,2,3,3,4,5]
    then sum(l1) = l1[0] + sum(l1[1:])
    return when list is empty
*)

(* Conventional to append 's' at end of list argument in SML*)
fun sum_list(xs : int list) =
                if null xs
                then 0
                else hd xs + sum_list(tl xs)

fun countdown(i : int) = 
                if i = 0
                then []
                else i::countdown(i - 1)

fun append(xs : int list, ys : int list) =
                if null xs
                then ys
                else hd xs :: append((tl xs), ys)


fun sum_pair_list(xs : (int * int) list) =
                if null xs
                then 0
                else #1 (hd xs) + #2 (hd xs) + sum_pair_list(tl xs)


fun seconds(xs : (int * int) list) =
                if null xs
                then []
                else #2 (hd xs) :: seconds(tl xs)

(* Using a let expression to store the result of a repeated recursive call *)
fun max_of_list(xs : int list) =
                if null xs
                then 0
                else 
                        let val tl_max = max_of_list(tl xs)
                        in 
                                if (hd xs) > tl_max
                                then (hd xs) 
                                else tl_max
                        end



fun sum_pair_lists(xs : (int * int) list) =
                if null xs
                then 0
                else 
                        #1 (hd xs) + #2 (hd xs) + sum_pair_lists(tl xs)

val l1 = [1,2,9,123,32,89,213,42,72];
val pairs = [(1,2), (3,4), (82,12)];
sum_pair_lists(pairs);