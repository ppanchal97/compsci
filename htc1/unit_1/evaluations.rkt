#lang racket

; Primitive Call Rule
; Call to a primitive: (<operator> <operands>)
; Order of operations for evaluating expressions:
; 0: Left to right, outside to inside:
    ; 1: Recursively reduce all operands to values
    ; 2: Then, apply primitives to the values.