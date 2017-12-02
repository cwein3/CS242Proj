type shape = [ `Triangle of float | `Square of float ]

let area s = match s with 
  | `Triangle len -> 0.433 *. len *. len
  | `Square len -> len *. len

let perimeter s = match s with
  | `Triangle len -> 3.0 *. len
  | `Square len -> 4.0 *. len

let angle s = match s with
  | `Triangle len -> 60.0
  | `Square len -> 90.0
  | `Hexagon len -> 120.0
 
let new_area s = match s with
  | #shape as x -> area x
  | `Hexagon len -> 2.598 *. len *. len

let new_perimeter s = match s with
  | #shape as x -> perimeter x
  | `Hexagon len -> 6.0 *. len
  
let rec gen_list n = 
    if n = 0 then []
    else match Random.int 3 with
      | 0 -> `Triangle 1.0 :: gen_list (n - 1)
      | 1 -> `Square 1.0 :: gen_list (n - 1)
      | _ -> `Hexagon 1.0 :: gen_list (n - 1)
      
let print_shape shape_plus =
    Printf.printf "Area: %f, Perimeter: %f, Angle: %f\n" (new_area shape_plus) (new_perimeter shape_plus) (angle shape_plus);;

let rec print_list shapes =
    List.iter print_shape shapes;;
      
print_list (gen_list 100000)
