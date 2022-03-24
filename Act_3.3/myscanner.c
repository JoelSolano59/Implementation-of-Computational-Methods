#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yylineno;
extern char* yytext;

int main(void){
    extern FILE *yyin, *yyout;

    yyin = fopen("input.txt","r");
    yyout = fopen("output.txt","w");

    int ntoken = yylex();
    while (ntoken){
        ntoken = yylex();
    }
    fclose(yyin);
    return 0;
}