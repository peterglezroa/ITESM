; Peter Glez
; A01651517
; Quiz 3
#lang racket

;; Auxiliar functions ========================================================
;; reverse
(define (rv lst res) (
    cond[(null? lst) res]
    [else (rv (rest lst) (cons (first lst) res))]
))
(define (rev lst) (rv lst empty))
(rev '(1 2 3 4)) ;'(4 3 2 1)

;; contains
(define (contains? lst x) (
    cond[(null? lst) #f]
    [(= (first lst) x) #t]
    [else (contains? (rest lst) x)]
))
(contains? '(1 2 3) 2) ;#t

;; Stack =====================================================================

; '(1 2 3 4)

;; push: pushes an element infront of the stack
(define (stack-push stack x) (cons x (rev stack)))
(stack-push '(1 2 3 4) 5) ;'(5 1 2 3 4)

;; pop: returns a list: (<stack after pop> <element popped>)
(define (stack-pop stack) (cons (rest stack) (first stack)))
(stack-pop '(1 2 3 4)) ;'((2 3 4) (1))

;; peek: returns the first element of the stack
(define (stack-peek stack) (first stack))
(stack-peek '(1 2 3 4)) ;1

;; Graph =====================================================================

; '((1 (2 3)) (2 ()) (3 (1)))

;; get-node: returns a specific node. If not found then returns empty
(define (graph-get-node graph node) (
    cond[(null? graph) empty]
    [(= (first (first graph)) node) (first graph)]
    [else (graph-get-node (rest graph) node)]
))
(graph-get-node '((1 (2 3)) (2 ()) (3 (1))) 1) ; (1 (2 3))

;; connected-to: returns a list where the node is connected to
(define (graph-connected-to graph node) (
    cond[(null? (graph-get-node graph node)) empty]
    [else (first (rest (graph-get-node graph node)))]
))
(graph-connected-to '((1 (2 3)) (2 ()) (3 (1))) 1) ; (2 3)

;; con-to-rec: returns a list where the node is connected to in all graph
;(define (graph-con-to-rec graph node) (
;))

;; add node
(define (graph-add-node graph name) (cons (cons name (cons empty empty)) graph))
(graph-add-node '((1 (2 3)) (2 ()) (3 (1))) 5) ; '((5()) (1(2 3)) (2()) (3(1)))

;; add arc
(define (gaa graph from to res) (
    cond[(null? graph) res]
    [else (
        cond[(null? graph) res]
        [(= (first (first graph)) from) (gaa (rest graph) from to (cons
            (cons (first (first graph)) (cons (cons to (first (rest (first graph)))) empty))
            res
        ))]
        [else (gaa (rest graph) from to (cons (first graph) res))]
    )]
))
(define (graph-add-arc graph from to) (gaa graph from to empty))
(graph-add-arc '((1 (2 3)) (2 ()) (3 (1))) 2 1)

;; search: returns if there is a path from node a to node b

;(define (gs graph from to res) (
;    cond[(null? (graph-get-node graph from)) empty]
;    [(contains? (graph-connected-to graph from) to) (rev (cons from res))]
;    [else (
;        cond[(null? (gs graph (first (graph-connected-to graph from))
;             ))
;    )]
;))

;(define (graph-search graph from to)(gs graph from to empty))

;; Bonus?
(lambda (x y) (cons x (cons y empty)) 1 2)
