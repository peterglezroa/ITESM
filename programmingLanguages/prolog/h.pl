countSLs([], 0).
countSLs([H|T], NoSLT):-
    isList(H),
    countSLs(T, NewSLT),
    NoSLT is NewSLT+1.

isList([]).
isList([_|_]).

printNos(0).
printNos(N):-
    NN is N - 1,
    printNos(NN),
    write(N),
    nl.
