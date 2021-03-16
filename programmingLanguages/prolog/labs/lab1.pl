% Pedro Luis González Roa
% A01651517
% Lab 01

% Compatible
% Returns if X has a hobby in common with Y
% Testcase: compatible(juan, simon) -> True
% Testcase: compatible(hans, juan) -> False
hobby(juan,kaggle).
hobby(luis,hack).
hobby(elena,tennis).
hobby(midori,videogame).
hobby(simon,sail).
hobby(simon,kaggle).
hobby(laura,hack).
hobby(hans,videogame).

compatible(X,Y):-
    hobby(X, Hobby),
    hobby(Y, Hobby).


% Can get to
% Returns if it is possible to get from a city to another city
% Testcase: can_get_to(placentia, roma) -> True
% Testcase: can_get_to(lilibeum, placentia) -> False
road(placentia, ariminum).
road(placentia, genua).
road(arimium, anconca).
road(anconca, roma).
road(genua, pisae).
road(pisae, roma).
road(capua, roma).
road(brundisium, capua).
road(rhegium, capua).
road(messana, rhegium).
road(catina, messana).
road(syracusae, catina).
road(lilibeum, messana).

can_get_to(Origin, Destination):- road(Origin, Destination).

can_get_to(Origin, Destination):-
    road(Origin, X),
    can_get_to(X, Destination).

test_can_get_to(X,Y,Z):-
    can_get_to(placentia, X),
    can_get_to(lilibeum, Y),
    can_get_to(arimium, Z).

% Predicate size
% Returns the number of cities crossed to get from a city to another.
% Testcase: size(catina, roma, X) -> 3
% Testcase: size(roma, catina, X) -> false
size(Origin, Destination, Count, Temp):-
    road(Origin, Destination),
    Count is Temp.

size(Origin, Destination, Count, Temp):-
    road(Origin, X),
    NewTemp is Temp +1,
    size(X, Destination, Count, NewTemp).

size(Origin, Destination, Count):-
    size(Origin, Destination, Count, 0).

test_size(X, Y, Z):-
    size(catina, roma, X),
    size(placentia, roma, Y),
    size(lilibeum, roma, Z).

% Predicate min
% Which Z is the minimal value between A, B and C
% Testcase: min(1, 5, 7, Z) -> 1
% Testcase: min(2, 2, 2, Z) -> 2
min(A, B, Z):-
    A > B,
    Z = B;
    Z = A.

min(A, B, C, Z):-
    min(A, B, X),
    min(X, C, Z).

test_min(X, Y, Z):-
    min(6, 2 ,3, X),
    min(2, 2, 2, Y),
    min(100, -100, 50, Z).

max(A, B, Z):-
    A > B,
    Z = A;
    Z = B.

max(A, B, C, Z):-
    max(A, B, X),
    max(X, C, Z).

% Predicate gcd
% Z is the greates common divisor of A and B
% Testcase: gcd(2, 5, Z) -> false
% Testcase: prediacte_gcd(15, 10, Z) -> 5
gcd(A, B, Z):-
    X is mod(A, B),
    X = 0,
    Z = B.

gcd(A, B, Z):-
    X is mod(A, B),
    gcd(B, X, Z).

test_gcd(X, Y, Z):-
    gcd(45, 10, X),
    gcd(7, 3, Y),
    gcd(9, 27, Z).
