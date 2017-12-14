(defrecord Triangle [length])
(defrecord Square [length])

(defmulti area class)
(defmulti perimeter class)

(defmethod area Triangle [t] (* 0.433 (* (:length t) (:length t))))
(defmethod area Square [s] (* (:length s) (:length s)))

(defmethod perimeter Triangle [t] (* 3.0 (:length t)))
(defmethod perimeter Square [s] (* 4.0 (:length s)))

(defmulti angle class)

(defmethod angle Triangle [t] 60.0)
(defmethod angle Square [s] 90.0)

(defrecord Hexagon [length])

(defmethod area Hexagon [h] (* 2.598 (* (:length h) (:length h))))
(defmethod perimeter Hexagon [h] (* 6.0 (:length h)))
(defmethod angle Hexagon [h] 120.0) 

(defn shape_map [i] (if (= i 0) (->Triangle 1.0) (if (= i 1) (->Square 1.0) (->Hexagon 1.0))))
(defn print_shape_map [i] (println (area (shape_map i)) (perimeter (shape_map i)) (angle (shape_map i))))

(doseq [shape (take 10000 (repeatedly #(rand-int 3)))] (print_shape_map shape))
