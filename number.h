/**
 @file number.h
 @author Tyler Strickland (tstrick2)
 Header file for the number10 and number25 source files. It defines behavior for the 
 skipSpace, parseValue, and printValue functions and also defines some constants. 
 */
/** Exit status indicating that the program was given invalid input. */
#define FAIL_INPUT 102 

/**
  Skips whitespace characters until it reads in a non whitespace character. It then 
  returns this character 
  @return the numeric code for the first non whitespace character
 */
int skipSpace();

/**
  Parses a single value within the expression and returns it in the desired base
  @return the value read in from input in the desired base
  */
long parseValue();

/**
  Prints the value passed in the parameter using recursion
  @param value the value to print out
  */
void printValue(long value);