% Pedro Luis González Roa
% Prolog
% Quiz 3

% born_in(some_guy, some_place).
born_in(chewbaka, kashyyk).
born_in(han_solo, corelia).
born_in(princess_leia, alderaan).
born_in(dark_vader, tatooine).
born_in(obi_wan_kenobi, tatooine).
born_in(luke_skywalker, tatooine).
born_in(yoda, dagobah).

% clan(fanboy, cult).
clan(yoda, jedi).
clan(luke_skywalker, jedi).
clan(obi_wan_kenobi, jedi).
clan(dark_vader, sith).

% side(yaboi, emo_face)
side(yoda, light).
side(luke_skywalker, light).
side(obi_wan_kenobi, light).
side(qui_gong_ji, light).
side(dark_vader, dark).
side(count_doku, dark).

% institution(almostslave, tec).
institution(dark_vader, empire).
institution(yoda, rebellion).
institution(obi_wan_kenobi, rebellion).
institution(luke_skywalker, rebellion).

% teaches(master, padawan).
teaches(yoda, count_doku).
teaches(yoda, luke_skywalker).
teaches(count_doku, qui_gong_jin).
teaches(qui_gong_jin, obi_wan_kenobi).
teaches(obi_wan_kenobi, luke_skywalker).
teaches(obi_wan_kenobi, dark_vader).

% friends
friends(han_solo, chewbaka).
friends(princess_leia, han_solo).
friends(chewbaka, princess_leia).
friends(obi_wan_kenobi, princess_leia).
friends(obi_wan_kenobi, han_solo).
friends(princess_leia, luke_skywalker).
friends(luke_skywalker, c3p0).
friends(luke_skywalker, r2d2).
friends(r2d2, c3p0).

% bad_parenting(teacher, padawan).
% returns if the padawan of someone (direct, or inside of the teaching tree)
% turned to the dark side.
bad_parenting(T, X):-
    teaches(T, X),
    side(X, dark);
    teaches(T, NewX),
    bad_parenting(NewX, X).

test_bad_parenting(X, Y, Z):-
    bad_parenting(yoda, X),
    bad_parenting(obi_wan_kenobi, Y),
    bad_parenting(qui_gong_jin, Z).

% cult_boys(list, cult).
% Returns a list of members of the given list that are on an specific cult
cult_boys([], _, R, R):-!.
cult_boys([H|T], C, R, Temp):-
    clan(H, C),
    !,
    cult_boys(T, C, R, [H|Temp]);
    cult_boys(T, C, R, Temp).

cult_boys(L, C, R):-
    cult_boys(L,C,R,[]).

test_cult_boys(X, Y):-
    cult_boys([yoda, luke_skywalker, han, dark_vader], jedi, X), % yoda, luke
    cult_boys([yoda, luke_skywalker, han, dark_vader], sith, Y). % dark_vader


% has
has([H|T], X):-
    H = X,
    !;
    has(T, X).

% facebook_pals(friend, friend).
% returns if they are friends of a friend and the path to get there (not best path)
facebook_pals(X, X, P, V):-
    P = [X|V].
facebook_pals(X, Y, P, V):-
    (friends(X, Other);friends(Other, X)),
    not(has(V, Other)),
    facebook_pals(Other, Y, P, [X|V]),
    !.

facebook_pals(X, Y, P):-
    facebook_pals(X, Y, P, []).

test_facebook_pals(X, Y):-
    facebook_pals(han_solo, c3p0, X),
    facebook_pals(chewbaka, princess_leia, Y).
