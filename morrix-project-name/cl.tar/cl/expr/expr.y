%{

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define YYSTYPE double

%}
%token NUMBER
%left '+' '-'
%left '*' '/'
%right UMINUS
%%

lines   : lines expr'\n' { printf ("%g\n", $2); }
        | lines '\n'
        |
        ;

expr    : expr '+' expr     { $$ = $1 + $3; printf ("%g\n", $$);}
        | expr '-' expr     { $$ = $1 - $3; }
        | expr '*' expr     { $$ = $1 * $3; }
        | expr '/' expr     { $$ = $1 / $3; }
        | '(' expr ')'      { $$ = $2; }
        | '-' expr %prec UMINUS { $$ = -$2; }
        | NUMBER
        ;
%%

yylex ()
{
  int c;

  /* skip white space  */
  while ((c = getchar ()) == ' ' || c == '\t')  
    ;
  /* process numbers   */
  if (c == '.' || isdigit (c))                
    {
      ungetc (c, stdin);
      scanf ("%lf", &yylval);
      return NUMBER;
    }
  /* return end-of-file  */
  if (c == EOF)                            
    return 0;
  /* return single chars */
  return c;                                
}

main()
{
    yyparse();
}


yyerror () {
    ;
}
