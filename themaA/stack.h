/* Header file: array_stack.h
 *
 * Stack implementation using an array
 *
 * Functions implemented:
 * full
 * empty
 * create
 * push
 * pop
 * print_stack
 * stack_count
 * topelement
 */

/* We create a struct named stack in order
 * to save all the info we need.
 * The struct stack has the following members
 * - contents: array of integers that will be
 * our stack
 * - top: current top position
 * - max_size: the maximum size in order to see if the stack is full
 */
typedef char stackElement; // A stack element is of type int

typedef struct stack {
  /* Pointer to an array of type stackElement (which is an alias of int)
  */
  stackElement *contents;
  int top; /* Here we save the current position of top */
  int max_size; /* The maximum number of elements the stack can have at a time */
} Stack;


int empty (Stack *stkPtr)
{
  return (stkPtr->top >= 0) ? 0 : 1;
  // if (stkPtr->top >= 0)
  // {
  //   return 0;
  // }
  // else
  // {
  //   return 1;
  // }
}

int stack_count (Stack *stkPtr)
{
  int count;
  if (empty (stkPtr))
    count = 0;
  else
    count = stkPtr->top + 1;

  return count;
}

/* Check if the stack is full */
int full (Stack *stkPtr)
{
  return (stkPtr->top == (stkPtr->max_size - 1)) ? 1: 0;

  // if (stkPtr->top == stkPtr->max_size - 1)
  //   return 1;
  // else
  //   return 0;
}

void create (Stack *stkPtr, int max_size)
{
  stkPtr->contents = (stackElement *) malloc (sizeof (stackElement) * max_size);
  if (stkPtr->contents == NULL)
  {
    printf ("Couldn't allocate memory for the stack. Exiting...\n");
    exit (1);
  }
  stkPtr->top = -1;
  stkPtr->max_size = max_size;
}

int pop (Stack *stkPtr)
{
  /* Checking if the stack is empty */
  if (empty (stkPtr))
  {
    printf ("The stack is empty. Action cannot be completed!\n");
    return -1;
  }

  return stkPtr->contents[stkPtr->top--];
}

void push (Stack *stkPtr, int value)
{
  /* Checking if the stack is full */
  if (full (stkPtr))
  {
    printf ("The stack is full. Action cannot be completed!\n");
    exit (1);
  }

  stkPtr->contents[++stkPtr->top] = value;
}

void print_stack (Stack *stkPtr)
{
  if (empty (stkPtr))
  {
    printf ("|   | -1 <-- Top\n");
    printf ("|---|\n\n");
  }
  else
  {
    int i;
    for (i = stkPtr->top; i >= 0; i--)
    {
      if (stkPtr->top == i)
        printf ("| %5c | %2d <-- Top\n", stkPtr->contents[i], i);
      else
        printf ("| %5c | %2d\n", stkPtr->contents[i], i);
      printf ("|-------| \n");
    }
    printf ("\n");
  }
}

void print_stack_line (Stack *stkPtr)
{
  char stack_str[81] = {'\0'};

  if (empty (stkPtr))
    printf ("%-21s", "ε");
  else
  {
      for (int i = 0; i < stkPtr->top + 1; ++i)
      {
        stack_str[i] = stkPtr->contents[i];
      }
      stack_str[stkPtr->top + 1] = '\0';
      printf ("%-20s", stack_str);
  }

}

char topelement (Stack *stkPtr)
{
  if (empty (stkPtr))
    printf ("The stack is empty.\n");
  else
    return stkPtr->contents[stkPtr->top];
}

void destroy (Stack *stkPtr)
{
  stkPtr->top = -1;
}

