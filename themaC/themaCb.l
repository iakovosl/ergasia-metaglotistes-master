%{
/* Θέμα Γ */
%}

whitespace [ \t]*
VERB Δίνεται
ENTITY (τρίγωνο|τετράγωνο|γωνία)
 /* NAME [Α|Β|Γ|Δ|Ε]+ */
NAME2 [A|B|C|D|E]+


%%

{whitespace} { /* do nothing */ }
{VERB} { printf ("%s: είναι ρήμα\n", yytext); }
{ENTITY} { printf ("%s: είναι γεωμετρική οντότητα\n", yytext); }
A{2,}[B|C|D|E]* { printf ("Το %s θα διορθωθεί\n", yytext); yyless(1); }
{NAME2} { printf ("%s: είναι όνομα γεωμετρικής οντότητας\n", yytext); }

%%

int main (int argc, char *argv[])
{
  yylex();

  return 0;
}
