reverseo(List):-listreverse(List,List).
listreverse([],[]).
listreverse([First|Rest],Reversed):-
    listreverse(Rest,ReversedRest),
    concatenation(ReversedRest,[First],Reversed).
concatenation([],L,L).
concatenation([X1,L1],L2,[X1|L3]):-concatenation(L1,L2,L3).



