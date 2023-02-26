#lang racket

(require test-engine/racket-tests)

; String -> String
; Append ! to a given string
(define (yell word)
    (string-append word "!"))

(check-expect (yell "Hello") "Hello!")
