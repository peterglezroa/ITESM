% Pedro Luis González Roa
% A01651517
% Lab 02

% Invert
% Inverts a list
invert([], R, R):- !.

invert([H|T], R, Temp):-
    invert(T, R, [H|Temp]).

invert(List, R):-
    invert(List, R, []).

test_invert(X, Y):-
    % [1,2,3]
    invert([3, 2, 1], X),
    % []
    invert([], Y).

% Any positive
% Returns if there is a positive number on the list
any_positive([H|T]):-
    H > 0;
    any_positive(T).

test_any_positive(X, Y, Z):-
    % true
    (any_positive([-2, -3, 4]) -> X=true; X=false),
    % false
    (any_positive([-1, -2]) -> Y=true; Y=false),
    % false
    (any_positive([]) -> Z=true; Z=false).


% Substitute
% Substitutes all the elements within a list with another element
substitute(_, _, [], R, Temp):-
    invert(Temp, R).

substitute(A, B, [H|T], R, Temp):-
    H = A,
    substitute(A, B, T, R, [B|Temp]);
    substitute(A, B, T, R, [H|Temp]).

substitute(A, B, List, R):-
    substitute(A, B, List, R, []).

test_substitute(X, Y, Z):-
    % [2,2,2,3,4]
    substitute(1, 2, [1, 1, 2, 3, 4], X),
    % [1,1,2,3,4]
    substitute(5, 2, [1, 1, 2, 3, 4], Y),
    % []
    substitute(5, 2, [], Z).


% has
% Checks if a list has an element
has([H|T], A):-
    H=A;
    has(T, A).


% eliminate_duplicates
% Eleminates duplicates
eliminate_duplicates([], R, Temp):-
    invert(Temp, R).

eliminate_duplicates([H|T], R, Temp):-
    has(Temp, H),
    eliminate_duplicates(T, R, Temp);
    eliminate_duplicates(T, R, [H|Temp]).

eliminate_duplicates(List, R):-
    eliminate_duplicates(List, R, []).

test_eliminate_duplicates(X, Y, Z):-
    % [1,2,3,4]
    eliminate_duplicates([1, 2, 3, 1, 2, 3, 3, 3, 4], X),
    % [1,2,3,4,5,6,7,8,9]
    eliminate_duplicates([1, 2, 3, 4, 5, 6 ,7 ,8 ,9], Y),
    % []
    eliminate_duplicates([], Z).


% Intersect
% Returns the intersection of 2 lists
intersect([], _, R, Temp):-
    invert(Temp, R).

intersect([H|T], List2, R, Temp):-
    has(List2, H),
    intersect(T, List2, R, [H|Temp]);
    intersect(T, List2, R, Temp).

intersect(List, List2, R):-
    intersect(List, List2, R, []).

test_intersect(U, V, X, Y, Z):-
    % [b,d]
    intersect([a,b,c,d], [b,d,e,f,g], U),
    % []
    intersect([a,x,c,i], [b,d,e,f,g], V),
    % []
    intersect([], [b,d,e,f,g], X),
    % []
    intersect([a,b], [], Y),
    % []
    intersect([], [], Z).


% Less than
% Returns the elements of a list that are less than a number
less_than(_, [], R, Temp):-
    invert(Temp, R).

less_than(X, [H|T], R, Temp):-
    X > H,
    less_than(X, T, R, [H|Temp]);
    less_than(X, T, R, Temp).

less_than(X, List, R):-
    less_than(X, List, R, []).

test_less_than(X, Y, Z):-
    % [1,2]
    less_than(5, [1,6,5,2,7], X),
    % []
    less_than(5, [9,6,5,8,7], Y),
    % []
    less_than(5, [], Z).


% More than or equal
% Returns the elements of a list that are more or equal to a number
more_equal(X,Y):-
    X > Y;
    X = Y.

more_than(_, [], R, Temp):-
    invert(Temp, R).

more_than(X, [H|T], R, Temp):-
    more_equal(H, X),
    more_than(X, T, R, [H|Temp]);
    more_than(X, T, R, Temp).

more_than(X, List, R):-
    more_than(X, List, R, []).

test_more_than(X, Y, Z):-
    % [6,5,7]
    more_than(5, [1,6,5,2,7], X),
    % []
    more_than(5, [1,2,3,4,0], Y),
    % []
    more_than(5, [], Z).


% size
% Returns the size of the list
size([], R, R):-!.

size([_|T], R, Temp):-
    NewTemp is Temp +1,
    size(T, R, NewTemp).

size(L, R):-
    size(L, R, 0).


% insert inverse
% Inserts the inverse of the second list to the first list
insert_inverse(R, [], R):-!.

insert_inverse(L, [H|T], R):-
    insert_inverse([H|L], T, R).


% Rotate
% Moves the elements of a list X spots to the right
rotate([], _, R, Te1, Te2):-
    invert(Te1, X),
    insert_inverse(X, Te2, R).

rotate([H|T], X, R, Te1, Te2):-
    X > 0,
    NewX is X -1,
    rotate(T, NewX, R, [H|Te1], Te2);
    rotate(T, 0, R, Te1, [H|Te2]).

rotate(L, X, R):-
    X > 0,
    rotate(L, X, R, [], []);
    size(L, S),
    NewX is S +X,
    rotate(L, NewX, R, [], []).

test_rotate(U, X, Y, Z):-
    % [2,7,1,6,5]
    rotate([1,6,5,2,7], 3, U),
    % [5,2,7,1,6]
    rotate([1,6,5,2,7], -3, X),
    % [1,6,5,2,7]
    rotate([1,6,5,2,7], 0, Y),
    % []
    rotate([], 2, Z).


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

% Connected
% Returns a list of all the places to which it is connected
connected(P, R, L):-
    road(P, X),
    not(has(L, X)),
    connected(P, R, [X|L]);
    road(X, P),
    not(has(L, X)),
    connected(P, R, [X|L]);
    R = L.

connected(P, R):-
    connected(P, R, []).

% addlists
addlists(L, [], R):-
    invert(L, R).

addlists(L, [H|T], R):-
    has(L, H),
    addlists(L, T, R);
    addlists([H|L], T, R).

addlists(L, L2, R):-
    invert(L, NewL),
    addlists(NewL, L2, R).

% subslists
subslists([], _, R, R):-!.

subslists([H|T], L2, R, Te):-
    has(L2, H),
    subslists(T, L2, R, Te);
    subslists(T, L2, R, [H|Te]).

subslists(L, L2, R):-
    subslists(L, L2, R, []).

% Path
% Finds the shortest path from a Origin to a Destination
path(O, D, R, V):-
    (not(has(V, D)),
        (road(O, D); road(D,O)),
        R = [O];
        (road(O, NewO); road(NewO, O)),
        not(has(V, NewO)),
        path(NewO, D, NewR, [O|V]),
        R = [O|NewR]
    ).

path(O, D, R):-
    path(O, D, R, [O]).
