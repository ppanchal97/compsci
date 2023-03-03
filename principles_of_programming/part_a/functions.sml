(* get the yth power for x - recursive implementation *)
fun pow(x : int, y: int) =
        if y=0
        then 1
        else x * pow(x, y - 1)


fun cube(x : int) =
        pow(x, 3)


val x = pow(2,3);
val y = cube(2);