fun bad_max (xs : int list) =
        if null xs
        then 0 (* note: bad style; see below *)
        else if null (tl xs)
            then hd xs
            else if hd xs > bad_max(tl xs)
                then hd xs
                else bad_max(tl xs)

fun better_max (xs : int list) =
        if null xs
        then NONE
        else
            let val tl_ans = better_max(tl xs)
            in if isSome tl_ans andalso valOf tl_ans > hd xs
                then tl_ans
                else SOME (hd xs)
            end

fun better_max2 (xs : int list) =
        if null xs
        then NONE
        else let (* fine to assume argument nonempty because it is local *)
                fun max_nonempty (xs : int list) =
                        if null (tl xs) (* xs must not be [] *)
                        then hd xs
                        else let val tl_ans = max_nonempty(tl xs)
                            in
                                if hd xs > tl_ans
                                then hd xs
                                else tl_ans
                            end
            in
                SOME (max_nonempty xs)
            end

val nums = [324,89,123,482,0,1];