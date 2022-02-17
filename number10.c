/**
  This code is responsible for reading in single values of expressions, converting them to
  base 10, and then printing the result in base 10. It uses the operation.h file to compute
  the expressions from input, and to detect overflow. 
  @file number10.c
  @author Tyler Strickland (tstrick2) 
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "operation.h"
 #include "number.h" 
 #include <stdbool.h>
 #include "limits.h"
 
/** Constant that represents the base the mathematical operations are working in */
 #define BASE 10
 
/**
  Skips over whitespace and returns the first non whitespace character found input
  @return the numerical code for the first non whitespace character found
  */
int skipSpace()
{
   int ch = getchar();
   
   while (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\v' || ch == '\f') {
      ch = getchar();
   } 
   
   return ch;
}

/**
  Parses a single value within the expression and returns it in the desired base
  @return the value read in from input in the desired base
  */
long parseValue() 
{
   int ch = skipSpace();
   bool neg = false;
   if (ch == '-') {
      neg = true;
      ch = getchar();
   }
   else if (ch == '+' || ch == '*' || ch == '/' || ch == '%' || ch == '(' || ch == ')') {
      exit(FAIL_INPUT);
   }
   
   long value = 0;
   int d = 0;
   while (ch >= '0' && ch <= 'Z') {
      if (ch >= '0' && ch <= '9') {
         d = ch - '0';
      }
      else {
         exit(FAIL_INPUT);
      }
      value = times(value, BASE);
      if ((LONG_MIN + value) * -1 == d && neg) {
         value = LONG_MIN;
         neg = false;
      }
      else {
         value = plus(value, d);
      }
      ch = getchar();
   
   }
   
   if (neg) {
      value = value * -1;
   }
   
   ungetc(ch, stdin);

   return value;

}

/**
  Prints the value passed into the parameter in the desired base
  @param value the value to print
  */
void printValue(long val)
{
   if (val == 0) {
      return;
   }
   int d = val % BASE;
   if (d < 0) {
      d = d * -1;
   }
   int ch = 0;
   if (d >= 10) {
      ch = d + 'A' - 10;
   }
   else {
      ch = d + '0';
   }
      
   printValue(val / BASE);
   putchar(ch);
}

