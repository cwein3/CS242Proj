(defrecord Triangle [length])
(defrecord Square [length])
(defrecord Hexagon [length])

(defn area [s] (if (= (type s) Triangle) (* 0.433 (* (:length s) (:length s))) (if (= (type s) Square) (* (:length s) (:length s)) (* 2.598 (* (:length s) (:length s))))))
(defn perimeter [s] (if (= (type s) Triangle) (* 3.0 (:length s)) (if (= (type s) Square) (* 4.0 (:length s)) (* 6.0 (:length s)))))
(defn angle [s] (if (= (type s) Triangle) 60.0 (if (= (type s) Square) 90.0 120.0)))

(defn shape_map [i] (if (= i 0) (->Triangle 1.0) (if (= i 1) (->Square 1.0) (->Hexagon 1.0))))
(defn print_shape_map [i] (println (area (shape_map i)) (perimeter (shape_map i)) (angle (shape_map i))))

(doseq [shape (take 10000 (repeatedly #(rand-int 3)))] (print_shape_map shape))
