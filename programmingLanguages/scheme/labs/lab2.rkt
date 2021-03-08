;; ITESM QRO
;; Pedro Luis González Roa A01651517
;; Scheme Lab 2

#lang racket
;; power-head
(define (power-head x y) (
   cond[(= y 1) x]
   [else (* (power-head x (- y 1)) x)]
))

(power-head 4 3)


;; power-tail
(define (pt x y acum) (
    cond[(= y 0) acum]
    [else (pt x (- y 1) (* acum x))]
))
(define (power-tail x y) (pt x y 1))

(power-tail 4 3)

;; Auxiliar function to get an num element from a list
(define (elem lst num) (
    cond[(< num 1) empty]
    [(null? lst) empty]
    [(= num 1) (first lst)]
    [else (elem (rest lst) (- num 1))]
))

;; Auxiliar to reverse a list
(define (rev lstA res) (
    cond[(null? lstA) res]
    [else (rev (rest lstA) (cons (first lstA) res))]
))

;; Auxiliar to add 2 lists
(define (add lstA lstB) (
    cond[(null? lstB) lstA]
    [else (add (cons (first lstB) lstA) (rest lstB))]
))

;; Auxiliar to see if a list contains an element
(define (pop lst x res)(
    cond [(null? lst) res]
    [(= (first lst) x) (add (rest lst) res)]
    [else (pop (rest lst) x (cons (first lst) res))]
))

;; third
(define (third lst) (elem lst 3))

(third (cons 1(cons 2 (cons 3 (cons 4 (cons 5 empty))))))

;; just-two?
(define (just-two? lst) (
    cond[(null? (elem lst 2)) #f]
    [else #t]
))

(just-two? (cons 1 empty))
(just-two? (cons 1 (cons 4 empty)))

;; how-many-x?
(define (hwmx lst x count)(
    cond [(null? lst) count]
    [(= (first lst) x) (+ (hwmx (rest lst) x (+ count 1)))]
    [else (hwmx (rest lst) x count)]
))
(define (how-many-x? lst x) (hwmx lst x 0))

(how-many-x? (cons 1(cons 2 (cons 3 (cons 4 (cons 3 empty))))) 3)

;; all-x?
(define (all-x? lst x) (
    cond[(null? lst) #t]
    [(= (first lst) x) (all-x? (rest lst) x)]
    [else #f]
))

(all-x? (cons 3(cons 3 (cons 3 (cons 3 (cons 3 empty))))) 3)
(all-x? (cons 3(cons 3 (cons 3 (cons 3 (cons 4 empty))))) 3)

;; get
(define (get lst x) (elem lst x))

(get (cons 1(cons 2 (cons 3 (cons 4 (cons 3 empty))))) 2)
(get (cons 1(cons 2 (cons 3 (cons 4 (cons 3 empty))))) 5)

;; difference
(define (difference lstA lstB) (
    cond[(null? lstB) lstA]
    [else (difference (pop lstA (first lstB) empty) (rest lstB))]
))

(difference '(12 44 55 77 66 1 2 3 4) '(1 2 3))


;; append
(define (append lstA lstB) (rev (add (rev lstA empty) lstB) empty))

(append '(a b c d) '(e f g))
(append  '( ) '(a b c))

;; invert
(define (invert lst) (rev lst empty))

(invert '(a b c d))
(invert '( ))

;; sign
(define (sgn lst res) (
    cond[(null? lst) res]
    [(< (first lst) 0) (sgn (rest lst) (cons -1 res))]
    [else (sgn (rest lst) (cons 1 res))]
))
(define (sign lst) (invert (sgn lst empty)))

(sign '(2 -4 -6))

;; negatives
(define (ngs lst res) (
    cond[(null? lst) res]
    [(< (first lst) 0) (ngs (rest lst) (cons (first lst) res))]
    [else (ngs (rest lst) (cons (* -1 (first lst)) res))]
))
(define (negatives lst) (invert (ngs lst empty)))

(negatives '(2 -4 6))
