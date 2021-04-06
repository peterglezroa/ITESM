% Pedro Luis González Roa
% A01651517
% Lab 03

% is_list
is_list([_|_]):-!.
is_list([]):-!.

% force_list
flist(X, Y):- (is_list(X), Y = X; Y = [X]), !.

% invert
invert([], L, L):-!.
invert([H|T], X, L):- invert(T, X, [H|L]).
invert(L, X):- invert(L, X, []).

% split
split([], L, R, L, R, _):- !.
split([H|T], XL, XR, L, R, S):-
    (
        S = 0, split(T, XL, XR, [H|L], R, 1);
        split(T, XL, XR, L, [H|R], 0)
    ), !.
split(L, XL, XR):- split(L, XL, XR, [], [], 0).

% merge
merge([], [], X, T):- invert(T, X).
merge([LH|LT], [], X, S):- merge(LT, [], X, [LH|S]), !.
merge([], [RH|RT], X, S):- merge(RT, [], X, [RH|S]), !.
merge([LH|LT], [RH|RT], X, S):-
    (
        LH > RH, merge([LH|LT], RT, X, [RH|S]);
        merge(LT, [RH|RT], X, [LH|S])
    ), !.
merge(L, R, X):- flist(L, FL), flist(R, FR), merge(FL, FR, X, []).

% merge sort
merge_sort([], []):- !.
merge_sort([X], X):-!.
merge_sort(List, X):-
    split(List, L, R),
    merge_sort(L, SL),
    merge_sort(R, SR),
    merge(SL, SR, X).

% test merge sort
test_merge_sort(V, X, Y, Z):-
    merge_sort([3, 1, 2, 7, 5, 6, 4, 9, 8], V), % 1,2,3,4,5,6,7,8,9
    merge_sort([1, 1, 1, 1, 2, 3, 1, 1, 1], X), % 1,1,1,1,1,1,1,2,3
    merge_sort([1], Y), % 1
    merge_sort([], Z). % []
