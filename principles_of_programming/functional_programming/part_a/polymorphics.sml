datatype 'a option = 
    NONE
| SOME of 'a

fun inc_or_zero intoption =
        case intoption of
            NONE => 0
        | SOME i => i+1