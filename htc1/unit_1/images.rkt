#lang racket

(require 2htdp/image)

; Stack of shapes
(above 
    (circle 10 "solid" "red")
    (rectangle 30 60 "outline" "blue")
)

; Overlay on top of other shapes
(overlay 
    (circle 10 "solid" "red")
    (circle 20 "solid" "blue")
    (circle 30 "solid" "green")
)
