(* Learning syntax - using hd and tl *)
fun sumList lst =
        if null lst
        then 0
        else hd lst + sumList (tl lst)


(* Idiomatic Syntax - using pattern matching *)
fun sumList(xs) =
        case xs of
            [] => 0
        | x::xs' => x + sumList xs'

fun appendToList(xs, ys) =
        case xs of
            [] => ys
        | x::xs' => x :: appendToList(xs', ys)


val nums = [];

sumList nums