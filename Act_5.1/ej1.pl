lasto([Y], Y).

lasto([_|Xs], Y) :- lasto(Xs, Y).