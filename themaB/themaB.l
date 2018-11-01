%{
/* Τμήμα Δηλώσεων */
%}

white_space [ \t]*
digit       [0-9]
alpha       [A-Za-z_]
alpha_num   ({alpha}|{digit})
identifier  {alpha}{alpha_num}*
type        (integer|boolean|real|char)

%%
%{
/* Τμήμα Κανόνων */
%}

{type} { printf ("%s is a Type \n", yytext); }
var { printf ("%s is a Keyword \n", yytext); }
{identifier} { printf ("%s is an Identifier \n", yytext); }
[,;:] { printf ("%s is a Symbol \n", yytext); }
{white_space} { /* Αγνοούμε τα κενά */ }

%%

int main (int argc, char *argv[])
{
  yylex();

  return 0;
}
