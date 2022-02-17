/**
  @file number25.c
  @author Tyler Strickland (tstrick2)
  This code is responsible for reading and writing values and calculations in base 25. It
  reads expressions in, and reports the result. If invalid input is detected, it 
  immediately exits the program.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "operation.h"
#include "number.h"
#include <stdbool.h>
#include "limits.h"

/** Represents the base this code is calculating the expressions in */ 
#define BASE 25

/** This constant is used to convert letters to numbers for base 25. We use it by 
    subtracting the code for 'A' from the parsed character code, and then adding this value.
    This makes the parsed letter represent its decimal value */
#define LETTER_TO_NUMBER 10

/**
  Skips over all whitespace and returns the first non-whitespace character that is found
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
  Reads a single number in the expression in base 25. If invalid input is passed in, 
  the program exits immediately
  @return the value read in from input in base 25
  */
long parseValue() 
{
   int ch = skipSpace();
   bool neg = false;
   if (ch == '+' || ch == '*' || ch == '/' || ch == '%' || ch == '(' || ch == ')') {
      exit(FAIL_INPUT);
   }
   if (ch == '-') {
      neg = true;
      ch = getchar();
   }
   long value = 0;
   int d = 0;
   while (ch >= '0' && ch <= 'Z') {
      if ( ch >= '0' && ch <= '9') {
         d = ch - '0';
      }
      else if (ch >= 'A' && ch <= 'O') {
         d = ch - 'A' + LETTER_TO_NUMBER;
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
  Prints the value of the expression in base 25. 
  @param val the value of the calculated expression to print in base 25
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
   if (d >= LETTER_TO_NUMBER) {
      ch = d + 'A' - LETTER_TO_NUMBER;
   }
   else {
      ch = d + '0';
   }
      
   printValue(val / BASE);
   putchar(ch);
   
   
   
}