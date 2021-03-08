;; ITESM QRO
;; Pedro Luis González Roa A01651517
;; Scheme Lab 2
#lang racket

;; Aux function
(define (all-x? lst x) (
    cond[(null? lst) #t]
    [(= (first lst) x) (all-x? (rest lst) x)]
    [else #f]
))

;; deep-all-x?
(define (deep-all-x? dlst x) (
    cond[(null? dlst) #t]
    [(list? (first dlst)) (
        cond[(all-x? (first dlst) x) (deep-all-x? (rest dlst) x)]
        [else #f]
    )]
    [(= (first dlst) x) (deep-all-x? (rest dlst) x)]
    [else #f]
))
(deep-all-x? '(1 (1 1) 1) 1) ; #t
(deep-all-x? '(1 (1 1) 2) 1) ; #f

; deep-reverse aux
(define (dr dlst res) (
    cond[(null? dlst) res]
    [(list? (first dlst)) (dr (rest dlst) (cons (dr (first dlst) empty) res))]
    [else (dr (rest dlst) (cons (first dlst) res))]
))
(define (deep-reverse dlst) (dr dlst empty))
(deep-reverse '(a (b (c d)) e (f g)))

;; Auxiliar to append a list to another list
(define (add lstA lstB) (
    cond[(null? lstB) lstA]
    [else (add (cons (first lstB) lstA) (rest lstB))]
))

;; Auxiliar to reverse a list
(define (rev lstA res) (
    cond[(null? lstA) res]
    [else (rev (rest lstA) (cons (first lstA) res))]
))

;; flatten
(define (flatn dlst res) (
    cond[(null? dlst) res]
    [(list? (first dlst)) (flatn (rest dlst)
        (add res (rev (flatn (first dlst) empty) empty)))]
    [else (flatn (rest dlst) (cons (first dlst) res))]
))
(define (flatten dlst) (rev (flatn dlst empty) empty))
(flatten '(a (b (c d)) e (f g)))

;; count-levels
(define (cl dlst res) (
    cond[(null? dlst) res]
    [(list? (first dlst)) (cl (rest dlst) (+ 1 res))]
    [else (cl (rest dlst) res)]
))
(define (count-levels dlst) (cl dlst 1))

(count-levels '(a (b (c)(d))(e(f)(g)))) ;3

;; aux: new-max
(define (new-max mx x) (
    cond[(> x mx) x]
    [else mx]
))

;; count-max-arity
(define (cma dlst mx cl)(
    cond[(null? dlst) mx]
    [(list? (first dlst)) (cma (rest dlst) (new-max (cma (first dlst) mx 0) (+ cl 1)) (+ cl 1))]
    [else (cma (rest dlst) mx cl)]
))

(define (count-max-arity dlst) (cma dlst 0 0))

(count-max-arity '(a (b (c) (d)) (e (f) (g) (h) (i)))) ;4
