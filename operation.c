/**
  @file operation.c
  @author Tyler Strickland
  This code is responsible for the mathematical operations that take place in the 
  calculator program. It adds, subtracts, multiplies, and divides two long integers and 
  can detect when overflow will occur. 
*/

#include <limits.h>
#include "operation.h"
#include <stdlib.h>
#include <stdio.h>
 
/**
  Adds two long integers together and returns the result. If overflow is detected, the 
  program exits immediately
  @param a the first long in the addition
  @param b the second long in the addition
  @return the sum of the two longs
*/
long plus (long a, long b) {
   if (a < 0 && b < 0) {
      if (a + b > 0) {
         exit(OVERFLOW);
      }
   }
   else if (a > 0 && b > 0) {
      if (a + b < 0) {
        exit(OVERFLOW);
      }
   }
   
   return a + b;
}

/**
  Subtracts two long integers and returns the result. If overflow is detected, the 
  program exits immediately
  @param a the first long in the subtraction
  @param b the second long in the subtraction
  @return the difference between the two longs
*/
long minus (long a, long b) {

   if (a > 0 && b < 0) {
      if (a - b < 0) {
         exit(OVERFLOW);
      }
   }
   
   if (a < 0 && b > 0) {
      if (a - b > 0) {
         exit(OVERFLOW);
      }
   }
   
   return a - b;
}

/**
  Multiplies two long integers and returns the result. If overflow is detected, the 
  program exits immediately
  @param a the first long in the product
  @param b the second long in the product
  @return the product of the two longs
*/
long times (long a, long b) {
   if (a > 0 && b > 0) {
      long x = LONG_MAX / b;
      long y = LONG_MAX / a;
      
      if (a > x || b > y) {
         exit(OVERFLOW);
      }
   }
   
   if (a < 0 && b < 0) {
      long x = LONG_MAX / b;
      long y = LONG_MAX / a;
      
      if (a < x || b < y) {
         exit(OVERFLOW);
      }
   }
   
   if (a > 0 && b < 0) {
      long x = LONG_MIN / b;
      long y = LONG_MIN / a;
      if (a > x || b < y) {
         exit(OVERFLOW);
      }
   }
   
   if (a < 0 && b > 0) {
      long x = LONG_MIN / b;
      long y = LONG_MIN / a;
      if (a < x || b > y) {
         exit(OVERFLOW);
      }
   }
   
   return a * b;
}

/**
  Divides two long integers and returns the result. If overflow is detected, the 
  program exits immediately
  @param a the first long in the quotient
  @param b the second long in the quotient
  @return the quotient between the two longs
*/
long divide (long a, long b) {
   if (b == 0) {
      exit(DIVIDE_BY_ZERO);
   }
   
   if (a == LONG_MIN && b == -1) {
      exit(OVERFLOW);
   }
   
   return a / b;
}