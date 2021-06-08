#lang racket
(cons 3 '(1 2 3))
(cons '(1 2 (3)) 3)

( (lambda (x y) (cons x (cons y empty))) 1 2)
