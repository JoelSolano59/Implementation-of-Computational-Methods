remove( _, [], []).
remove( R, [R|T], T2) :- remove( R, T, T2).
remove( R, [H|T], [H|T2]) :- H \= R, remove( R, T, T2).