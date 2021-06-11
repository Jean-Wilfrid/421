char* locate(char* str, char c);
/*Locate the first occurence of a character in a string*/

int read (char* str, int length);
/*Reads an input from the standart input with at most one less than length. The final null  byte '\0' is stored at the end of the string*/

void cleanBuffer();
/*Get all the characters reamining in the buffer*/

#include "ownRead.c"