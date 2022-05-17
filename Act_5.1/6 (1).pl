reverseo(List):-palindrome(List,List).
palindrome([],[]).
palindrome([F|R],Rev):-
    palindrome(R,RevRest),
    concat(RevRest,[F],Rev).
concat([],L,L).
concat([X1,L1],L2,[X1|L3]):-concat(L1,L2,L3).



