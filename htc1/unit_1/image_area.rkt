#lang racket

(require 2htdp/image)
(require test-engine/racket-tests)

(check-expect (image-area (rectangle 2 3 "solid" "red")) (* 2 3))

(define (image-area img)
    (* (image-height img) (image-width img)))
