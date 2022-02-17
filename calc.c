/**
  @file calc.c
  @author Tyler Strickland (tstrick2)
  This code is the driving source of the calc program. It contains the main function, and 
  with the help of the operation.h and the number.h header files, is able to read in 
  mathematical expressions and return the result in the correct base.
 */
 
#include "number.h"
#include "operation.h"
#include <stdio.h>
#include <stdlib.h>

 
/**
  Parses an entire term in the mathematical expression. It computes all multiplication
  and division and returns the result in order to keep precedence within the expression.
  @return the result of the multiplication and division
 */
static long parseTerm() 
{
   long result = parseValue();
   int ch = skipSpace();
   while (ch != '\n' && ch != EOF) {
      if (ch == '+') {
         ungetc(ch, stdin);
         return result;
      }
      else if (ch == '-') {
         ungetc(ch, stdin);
         return result;
      }
      else if (ch == '*') {
         long b = parseValue();
         result = times(result, b);
      }
      else if (ch == '/') {
         long b = parseValue();
         result = divide(result, b);
      }
      else if (ch == '(' || ch == '%' || ch == ')') {
         exit(FAIL_INPUT);
      }
      ch = getchar();
      
   }
   
   return result;
   
}

/**
  Main function and starting point for the calc program. It reads in terms calculated from
  the parseTerm function and adds and subtracts them depending on what is requested by the 
  input expression. It then prints the result with the help of other functions. 
  @return exit status code for the program. 
  */
int main() 
{
     long result = parseTerm();
     int ch = getchar();
     while (ch != '\n' && ch != EOF) {
        if (ch == '+') {
           long b = parseTerm();
           result = plus(result, b);
        }
        else if (ch == '-') {
           long b = parseTerm();
           result = minus(result, b);
        }
        ch = getchar();
     }
     if (result == 0) {
        printf("0\n");
     }
     else if (result < 0) {
        putchar('-');
        printValue(result);
        printf("\n");
     }
     else {
        printValue(result);
        printf("\n");
     }
     
    return EXIT_SUCCESS;
}