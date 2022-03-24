%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
:                       fprintf(yyout, "%s\n","Encontrado\t:");
"db_type"               fprintf(yyout, "%s\n","Encontrado\tdb_type");
"db_name"               fprintf(yyout, "%s\n","Encontrado\tdb_name");
"db_table_prefix"       fprintf(yyout, "%s\n","Encontrado\tdb_table_prefix");
"db_port"               fprintf(yyout, "%s\n","Encontrado\tdb_port");

[a-zA-Z][_a-aA-Z0-9]*   fprintf(yyout, "%s\n","Encontrado\tVariable");
[1-9][0-9]*             fprintf(yyout, "%s\n","Encontrado\tNumero");
[ \t\n]                 ;
.                       fprintf(yyout, "%s\n","Error");
%%

int yywrap(void){
    return 1;
}