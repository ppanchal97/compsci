;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname sandbox) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))


(require 2htdp/image)

; Purpose: a function that consumes 2 images and determines if the first is larger than the second
; (define (is-larger (img1 img2)))
(check-expect (is-larger (rectangle 2 3 "solid" "red" ) (rectangle 5 6 "solid" "red")) false)

(define (is-larger img1 img2)
    (> (* (image-height img1) (image-width img1)) (* (image-height img2) (image-width img2))))