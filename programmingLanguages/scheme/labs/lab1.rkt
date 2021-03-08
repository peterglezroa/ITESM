;; ITESM QRO
;; Pedro Luis González Roa A01651517
;; Lab 1

#lang racket
;; Helper function that returns the cuadratic of a number
(define (cuad n) (* n n) )

;; Area of a triangle
(define (atri base height) (/(* base height) 2) )
(atri 2 3)

;; Function A
(define (a n) (+(cuad n) 10) )
(a 10)

;; Function B
(define (b n) (+(/(cuad n) 2) 20) )
(b 10)

;; Function C
(define (c n) (- 2 (/ 1 n)) )
(c 10)

;; Functon Solutions
;; Returns the amount of possible solutions the equation a(x^2)+bx+c=0
(define (solutions a b c)
    (if (> (cuad b) (* 4 a c))
       2
       (if (= (cuad b) (* 4 a c))
           1
           0
       )
   )
)
(solutions 1 0 -1)