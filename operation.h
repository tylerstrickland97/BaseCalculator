/**
 @file operation.h
 @author Tyler Strickland (tstrick2)
 Header file for the operation.c file. It defines behavior for the operation.c file and 
 defines a constant. 
 */
 
 /** Exit status when overflow is detected during mathematical operations */
#define OVERFLOW 100

/** Exit status when there is an attempted divide by 0 */
#define DIVIDE_BY_ZERO 101
/**
 Adds two longs together and returns the result. If overflow is detected, the program is
 exited immediately. 
 @param a the first long in the addition
 @param b the second long in the addition
 @return the result of the addition
 */
long plus(long a, long b);

/**
 Subtracts two longs and returns the result. If overflow is detected, the program is
 exited immediately. 
 @param a the first long in the subtraction
 @param b the second long in the subtraction
 @return the result of the subtraction
 */
long minus(long a, long b);

/**
 Multiplies two longs and returns the result. If overflow is detected, the program is
 exited immediately. 
 @param a the first long in the product
 @param b the second long in the product
 @return the product of a and b
 */
long times(long a, long b);

/**
 Divides two longs and returns the result. If overflow is detected, the program is
 exited immediately. 
 @param a the first long in the division
 @param b the second long in the division
 @return the division between a and b
 */
long divide(long a, long b);