%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
\/\/.*                          fprintf(yyout, "comentario ");fprintf(yyout, "%s\n", yytext);

"#define"                       fprintf(yyout, "definir ");fprintf(yyout, "%s\n", yytext);
"#include"                      fprintf(yyout, "incluir ");fprintf(yyout, "%s\n", yytext);
\<[^[:blank:]][a-zA-Z]*[^[:blank:]].[^[:blank:]]h\> fprintf(yyout, "libreria ");fprintf(yyout, "%s\n", yytext);

\{                              fprintf(yyout, "bloque ");fprintf(yyout, "%s\n", yytext);
\}                              fprintf(yyout, "bloque ");fprintf(yyout, "%s\n", yytext);
\(                              fprintf(yyout, "funcion ");fprintf(yyout, "%s\n", yytext);
\)                              fprintf(yyout, "funcion ");fprintf(yyout, "%s\n", yytext);
\[                              fprintf(yyout, "elemento_vector ");fprintf(yyout, "%s\n", yytext);
\]                              fprintf(yyout, "elemento_vector ");fprintf(yyout, "%s\n", yytext);
\:                              fprintf(yyout, "delimitador ");fprintf(yyout, "%s\n", yytext);
\"                              fprintf(yyout, "comillas ");fprintf(yyout, "%s\n", yytext);
\;                              fprintf(yyout, "nula ");fprintf(yyout, "%s\n", yytext);

"auto"	                        fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"const"	                        fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"extern"	                    fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"register"	                    fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"short"	                        fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"signed"	                    fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"static"	                    fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"struct"	                    fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"union"	                        fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"unsigned"	                    fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"volatile"	                    fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);

"char"	                        fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"int"	                        fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"long"	                        fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"long long"                     fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"float"	                        fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"bool"                          fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"double"	                    fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"void"	                        fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"enum"	                        fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);

"true"                          fprintf(yyout, "estado ");fprintf(yyout, "%s\n", yytext);
"false"                         fprintf(yyout, "estado ");fprintf(yyout, "%s\n", yytext);

"do"	                        fprintf(yyout, "bucle ");fprintf(yyout, "%s\n", yytext);
"while"	                        fprintf(yyout, "bucle ");fprintf(yyout, "%s\n", yytext);
"for"	                        fprintf(yyout, "bucle ");fprintf(yyout, "%s\n", yytext);

"case"	                        fprintf(yyout, "etiqueta ");fprintf(yyout, "%s\n", yytext);
"default"	                    fprintf(yyout, "etiqueta ");fprintf(yyout, "%s\n", yytext);

"break"	                        fprintf(yyout, "salto ");fprintf(yyout, "%s\n", yytext);
"continue"	                    fprintf(yyout, "salto ");fprintf(yyout, "%s\n", yytext);
"goto"	                        fprintf(yyout, "salto ");fprintf(yyout, "%s\n", yytext);
"return"	                    fprintf(yyout, "salto ");fprintf(yyout, "%s\n", yytext);

"if"	                        fprintf(yyout, "seleccion ");fprintf(yyout, "%s\n", yytext);
"else"	                        fprintf(yyout, "seleccion ");fprintf(yyout, "%s\n", yytext);
"switch"	                    fprintf(yyout, "seleccion ");fprintf(yyout, "%s\n", yytext);

"cout"                          fprintf(yyout, "salida_consola ");fprintf(yyout, "%s\n", yytext);
"cin"                           fprintf(yyout, "entrada_consola ");fprintf(yyout, "%s\n", yytext);


\+[^[:blank:]][a-zA-Z_0-9]*     fprintf(yyout, "operador_aritmetico ");fprintf(yyout, "%s\n", yytext);
\+\+[^[:blank:]][a-zA-Z_0-9]*   fprintf(yyout, "operador_aritmetico ");fprintf(yyout, "%s\n", yytext);
[a-zA-Z_0-9]*[^[:blank:]]\+\+   fprintf(yyout, "operador_aritmetico ");fprintf(yyout, "%s\n", yytext);
\-[^[:blank:]][a-zA-Z_0-9]*     fprintf(yyout, "operador_aritmetico ");fprintf(yyout, "%s\n", yytext);
\-\-[^[:blank:]][a-zA-Z_0-9]*   fprintf(yyout, "operador_aritmetico ");fprintf(yyout, "%s\n", yytext);
[a-zA-Z_0-9]*[^[:blank:]]\-\-   fprintf(yyout, "operador_aritmetico ");fprintf(yyout, "%s\n", yytext);
\+                              fprintf(yyout, "operador_aritmetico ");fprintf(yyout, "%s\n", yytext);
\-                              fprintf(yyout, "operador_aritmetico ");fprintf(yyout, "%s\n", yytext);
\*                              fprintf(yyout, "operador_aritmetico ");fprintf(yyout, "%s\n", yytext);
\/                              fprintf(yyout, "operador_aritmetico ");fprintf(yyout, "%s\n", yytext);
\%                              fprintf(yyout, "operador_aritmetico ");fprintf(yyout, "%s\n", yytext);

\<                              fprintf(yyout, "operador_comparacion ");fprintf(yyout, "%s\n", yytext);
\>                              fprintf(yyout, "operador_comparacion ");fprintf(yyout, "%s\n", yytext);
\<\=                            fprintf(yyout, "operador_comparacion ");fprintf(yyout, "%s\n", yytext);
\>\=                            fprintf(yyout, "operador_comparacion ");fprintf(yyout, "%s\n", yytext);
\=\=                            fprintf(yyout, "operador_comparacion ");fprintf(yyout, "%s\n", yytext);
\!\=                            fprintf(yyout, "operador_comparacion ");fprintf(yyout, "%s\n", yytext);

\![^[:blank:]][a-zA-Z_0-9]*     fprintf(yyout, "operador_logico ");fprintf(yyout, "%s\n", yytext);
\&\&                            fprintf(yyout, "operador_logico ");fprintf(yyout, "%s\n", yytext);
\|\|                            fprintf(yyout, "operador_logico ");fprintf(yyout, "%s\n", yytext);

\~[^[:blank:]][a-zA-Z_0-9]*     fprintf(yyout, "operador_bit ");fprintf(yyout, "%s\n", yytext);
\<\<                            fprintf(yyout, "operador_bit ");fprintf(yyout, "%s\n", yytext);
\>\>                            fprintf(yyout, "operador_bit ");fprintf(yyout, "%s\n", yytext);
\&                              fprintf(yyout, "operador_bit ");fprintf(yyout, "%s\n", yytext);
\|                              fprintf(yyout, "operador_bit ");fprintf(yyout, "%s\n", yytext);
\^                              fprintf(yyout, "operador_bit ");fprintf(yyout, "%s\n", yytext);

\-\>                            fprintf(yyout, "operador_puntero ");fprintf(yyout, "%s\n", yytext);
\-\>\*                          fprintf(yyout, "operador_puntero ");fprintf(yyout, "%s\n", yytext);
\.\*                            fprintf(yyout, "operador_puntero ");fprintf(yyout, "%s\n", yytext);

\=                              fprintf(yyout, "asignacion ");fprintf(yyout, "%s\n", yytext);
\+\=                            fprintf(yyout, "asignacion ");fprintf(yyout, "%s\n", yytext);
\-\=                            fprintf(yyout, "asignacion ");fprintf(yyout, "%s\n", yytext);
\*\=                            fprintf(yyout, "asignacion ");fprintf(yyout, "%s\n", yytext);
\/\=                            fprintf(yyout, "asignacion ");fprintf(yyout, "%s\n", yytext);
\%\=                            fprintf(yyout, "asignacion ");fprintf(yyout, "%s\n", yytext);
\<\<\=                          fprintf(yyout, "asignacion ");fprintf(yyout, "%s\n", yytext);
\>\>\=                          fprintf(yyout, "asignacion ");fprintf(yyout, "%s\n", yytext);
\&\=                            fprintf(yyout, "asignacion ");fprintf(yyout, "%s\n", yytext);
\^\=                            fprintf(yyout, "asignacion ");fprintf(yyout, "%s\n", yytext);
\|\=                            fprintf(yyout, "asignacion ");fprintf(yyout, "%s\n", yytext);

"sizeof"                        fprintf(yyout, "operador ");fprintf(yyout, "%s\n", yytext);
"new"                           fprintf(yyout, "operador ");fprintf(yyout, "%s\n", yytext);
"delete"                        fprintf(yyout, "operador ");fprintf(yyout, "%s\n", yytext);
"throw"                         fprintf(yyout, "operador ");fprintf(yyout, "%s\n", yytext);
\*[^[:blank:]][a-zA-Z_0-9]*     fprintf(yyout, "operador ");fprintf(yyout, "%s\n", yytext);
\&[^[:blank:]][a-zA-Z_0-9]*     fprintf(yyout, "operador ");fprintf(yyout, "%s\n", yytext);
\:\:                            fprintf(yyout, "operador ");fprintf(yyout, "%s\n", yytext);
\.                              fprintf(yyout, "operador ");fprintf(yyout, "%s\n", yytext);
\,                              fprintf(yyout, "operador ");fprintf(yyout, "%s\n", yytext);

[0-9]*                          fprintf(yyout, "entero ");fprintf(yyout, "%s\n", yytext);
[0-9]*[^[:blank:]]\.[0-9]*      fprintf(yyout, "flotante ");fprintf(yyout, "%s\n", yytext);
[a-zA-Z_0-9]*                   fprintf(yyout, "variable ");fprintf(yyout, "%s\n", yytext);

[ \t]                           ;
[\n]                            fprintf(yyout, "salto ");fprintf(yyout, "%s\n", "<br/>");
%%

int yywrap(void){
    return 1;
}