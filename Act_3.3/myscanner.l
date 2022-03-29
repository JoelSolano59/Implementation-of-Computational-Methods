%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
\/\/.*                          fprintf(yyout, "comentario ");fprintf(yyout, "%s\n", yytext);

"#define"                       fprintf(yyout, "definir ");fprintf(yyout, "%s\n", yytext);
"#include"                      fprintf(yyout, "incluir ");fprintf(yyout, "%s\n", yytext);
"import"                        fprintf(yyout, "incluir ");fprintf(yyout, "%s\n", yytext);
"from"                          fprintf(yyout, "incluir ");fprintf(yyout, "%s\n", yytext);
\<[^[:blank:]][a-zA-Z]*[^[:blank:]].[^[:blank:]]h\> fprintf(yyout, "libreria ");fprintf(yyout, "%s\n", yytext);

"<?php"                         fprintf(yyout, "bloque ");fprintf(yyout, "%s\n", yytext);
"?>"                            fprintf(yyout, "bloque ");fprintf(yyout, "%s\n", yytext);
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
"def"                           fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"pass"                          fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"is"                            fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"in"                            fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"list"                          fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"range"                         fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"lambda"                        fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"yield"                         fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"class"                         fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"del"                           fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"open"                          fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"as"                            fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"with"                          fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"async"                         fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"await"                         fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"clone"                         fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"die"                           fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"empty"                         fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"endswitch"                     fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"final"                         fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"function"                      fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"isset"                         fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"require"                       fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"throw"                         fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);
"var"                           fprintf(yyout, "palabra_reservada ");fprintf(yyout, "%s\n", yytext);

"__CLASS__"                     fprintf(yyout, "constantes_compilacion ");fprintf(yyout, "%s\n", yytext);
"__DIR__"                       fprintf(yyout, "constantes_compilacion ");fprintf(yyout, "%s\n", yytext);
"__FILE__"                      fprintf(yyout, "constantes_compilacion ");fprintf(yyout, "%s\n", yytext);
"__FUNCTION__"                  fprintf(yyout, "constantes_compilacion ");fprintf(yyout, "%s\n", yytext);
"__LINE__"                      fprintf(yyout, "constantes_compilacion ");fprintf(yyout, "%s\n", yytext);
"__METHOD__"                    fprintf(yyout, "constantes_compilacion ");fprintf(yyout, "%s\n", yytext);
"__NAMESPACE__"                 fprintf(yyout, "constantes_compilacion ");fprintf(yyout, "%s\n", yytext);
"__TRAIT__"	                    fprintf(yyout, "constantes_compilacion ");fprintf(yyout, "%s\n", yytext);

"char"	                        fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"int"	                        fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"long"	                        fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"long long"                     fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"float"	                        fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"bool"                          fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"double"	                    fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"void"	                        fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"enum"	                        fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"null"                          fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"None"                          fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"global"                        fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);
"nonlocal"                      fprintf(yyout, "tipo_variable ");fprintf(yyout, "%s\n", yytext);

"true"                          fprintf(yyout, "estado ");fprintf(yyout, "%s\n", yytext);
"false"                         fprintf(yyout, "estado ");fprintf(yyout, "%s\n", yytext);
"True"                          fprintf(yyout, "estado ");fprintf(yyout, "%s\n", yytext);
"False"                         fprintf(yyout, "estado ");fprintf(yyout, "%s\n", yytext);

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
"print"                         fprintf(yyout, "salida_consola ");fprintf(yyout, "%s\n", yytext);
"printf"                        fprintf(yyout, "salida_consola ");fprintf(yyout, "%s\n", yytext);
"fprintf"                       fprintf(yyout, "salida_consola ");fprintf(yyout, "%s\n", yytext);
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

"not"                           fprintf(yyout, "operador_logico ");fprintf(yyout, "%s\n", yytext);
"and"                           fprintf(yyout, "operador_logico ");fprintf(yyout, "%s\n", yytext);
"or"                            fprintf(yyout, "operador_logico ");fprintf(yyout, "%s\n", yytext);
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

"abs"                           fprintf(yyout, "operador ");fprintf(yyout, "%s\n", yytext);
"complex"                       fprintf(yyout, "operador ");fprintf(yyout, "%s\n", yytext);
"c.conjugate"                   fprintf(yyout, "operador ");fprintf(yyout, "%s\n", yytext);
"divmod"                        fprintf(yyout, "operador ");fprintf(yyout, "%s\n", yytext);
"pow"                           fprintf(yyout, "operador ");fprintf(yyout, "%s\n", yytext);
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
\$[a-zA-Z_0-9]*                 fprintf(yyout, "variable ");fprintf(yyout, "%s\n", yytext);
[a-zA-Z_0-9]*                   fprintf(yyout, "variable ");fprintf(yyout, "%s\n", yytext);

[ \t]                           ;
[\n]                            fprintf(yyout, "salto ");fprintf(yyout, "%s\n", "<br/>");
%%

int yywrap(void){
    return 1;
}