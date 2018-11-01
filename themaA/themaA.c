#include <stdio.h> // Για printf και scanf
#include <stdlib.h>
#include <string.h> // Για το strlen ()
#include "stack.h" // Υλοποίηση δομής στοίβας και απαραίτητων συναρτήσεων

#define L 'L'
#define R 'X'

void print_status (Stack *stk, char expression[], char status[], int index);
void parse_expression (char expression[], int length);
void print_remaining_input (char expression[], int index);
int isPair (char top, char end);

int main (int argc, char *argv[])
{
  char expression[80];
  int length = 0;
  puts ("Παρακαλώ δώστε έκφραση για έλεγχο:");
  scanf ("%s", expression); 

  length = strlen (expression);
  printf ("Έκφραση: %s, Μήκος: %d χαρακτήρες\n", expression, length);

  printf ("\nRunning expression parser...\n");
  parse_expression (expression, length);

  return 0;
}

void parse_expression (char expression[], int length)
{
  Stack stk;              // Δημιουργούμε το stack
  create (&stk, length);  // Αρχικοποιούμε τον πίνακα του stack με lenth
  char c;

  printf ("%25s | Κατάσταση | %25s\n", "Περιεχόμεντα Στοίβας", "Υπόλοιπο Εισόδου");
  printf ("---------------------------------------------------\n");

  // Αρχική κατάσταση S0
  print_status (&stk, expression, "S0", 0); // Κατάσταση S0
  push (&stk, '$'); /* Προσθέτουμε στην άδεια στοίβα το $ που δηλώνει τον 
                     * πυθμένα της στοίβας.
                     */
  print_status (&stk, expression, "S1", 0); // Κατάσταση S1

  // Κάνουμε loop σε όλους τους χαρακτήρες της έκφρασης
  for (int i = 0; i < length; ++i)
  {
    // Αποθηκεύουμε τον τρέχων χαρακτήρα
    c = expression[i];

    // Ελέγχουμε αν έχουμε αριστερή παρένθεση (χαρακτήρα ανοίγματος)
    if (c == L)
    {
      // Αφού συναντήσαμε αριστερό χαρακτήρα τον προσθέτουμς στη στοίβα
      push (&stk, c);
    }
    else if (c == R) // Συναντάμε δεξιό χαρακτήρα
    {
      // Αν η στοίβα είναι άδεια ή δεν ταιριάζουν ο τρέχων χαρακτήρας
      // και ο χαρακτήρας κορυφής της στοίβας δεν αναγνωρίζουμε την έκφραση
      if (empty (&stk) || !isPair (topelement (&stk), c))
      {
        printf ("\nNO\n");
        return; // To πρόγραμμα επιστρέφει στη main
      }
      else // Διαφορετικά έχουμε συναντήσει δεξιό χαρακτήρα (που ταιριάζει) 
           // και βγάζουμε τον χαρακτήρα κορυφής από τη στοίβα
      {
        pop (&stk);
      }
    } // End else if

    // Γραμμή εκτύπωσης με τα περιεχόμενα της στοίβας, την τρέχουσα κατάσταση
    // και τα υπόλοιπα σύμβολα εισόδου
    print_status (&stk, expression, "S1", i + 1); // Κατάσταση S1      
  } // End for

  pop (&stk); /* Αφαιρούμε το σύμβολο πυθμένα της στοίβας */

  /* Αν η στοίβα είναι άδεια τότε έχουμε φτάσει στην τελική κατάσταση
   * και αποδεχόμαστε τη συμβολοσειρά εισόδου
   */
  // Κατάσταση ST αν η στοίβα είναι άδεια
  if (empty (&stk))
  {
    print_status (&stk, expression, "ST", length); // Τελική κατάσταση
    printf ("\nYES\n");
  }
  else
  {
    printf ("\nNO\n");
  }
}

void print_status (Stack *stk, char expression[], char status [], int index)
{
  print_stack_line (stk);
  printf (" | %-9s | ", status);
  print_remaining_input (expression, index);
  puts ("");
}

int isPair (char top, char end)
{
  char validPair[] = { L, R };

  if (validPair[0] == top && validPair[1] == end)
    return 1;
  else
    return 0;
}

void print_remaining_input (char expression[], int index)
{
  char c;
  while ((c = expression[index++]) != '\0')
  {
    printf ("%c", c);
  }
}
