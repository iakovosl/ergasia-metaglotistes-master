%option noyywrap
%{
/* Θέμα Γ */
%}

whitespace [ \t]*
VERB Δίνεται
ENTITY (τρίγωνο|τετράγωνο|γωνία)
NAME [Α|Β|Γ|Δ|Ε]+


%%

{whitespace} { /* do nothing */ }
{VERB} { printf ("%s: είναι ρήμα\n", yytext); }
{ENTITY} { printf ("%s: είναι γεωμετρική οντότητα\n", yytext); }
{NAME} { printf ("%s: είναι όνομα γεωμετρικής οντότητας\n", yytext); }

%%

int main (int argc, char *argv[])
{
  yylex();

  return 0;
}
