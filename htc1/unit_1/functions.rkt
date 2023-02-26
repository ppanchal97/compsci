#lang racket

(define (pythagoras a b)
    (sqrt (+ (sqr a) (sqr b))))

(pythagoras 3 4)