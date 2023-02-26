#lang racket

(require 2htdp/image)

; Signature: image, image -> boolean
; Purpose: a function that consumes 2 images and determines if the first is larger than the second
(check-expect (is-larger (rectangle 2 3 "solid" "red" ) (rectangle 5 6 "solid" "red")) false)
(check-expect (is-larger (rectangle 22 30 "solid" "red" ) (rectangle 5 6 "solid" "red")) true)

(define (is-larger img1 img2)
    (> (* (image-height img1) (image-width img1)) (* (image-height img2) (image-width img2))))