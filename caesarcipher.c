#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Program to implement a caesar cipher solver ****************************
* Author                Dept.           Date            Notes
************************************************************************
* Tahseen T.            Comp. Science.  Feb 20 2020     Initial version.
*/

// declare an array which contains the string of shifted characters
char shifted[100];
char* shifter(char* clear, int s) {
	// loop through all the characters of the given string until newline
	// perform the shift and return it if it is within the lowercase characters range
	// or else add 26 to enter the lowercase character range
        for (int i = 0; clear[i]!= '\n'; i++) {
          if (clear[i]>= 'a' && clear[i]<= 'z') {
              shifted[i] = ((clear[i]-97+s)%26)+97;
              if (shifted[i]<'a') {
                shifted[i]=shifted[i]+26;
              }
          }
	// if the given input is not a valid lowercase character, don't shift it
          else{
            shifted[i] = clear[i];
          }
        }
        return shifted;
}
int main(int argc, char *argv[]) {
	// return an error message if illegal number of inputs are provided
        if (argc != 2) {
          puts("Error: usage is caesarcipher <offset>");
          return 1;
        }
	// convert the given input to an integer to operate using it later
        int shift = atoi(argv[1]);
        do {
	// keep looping through the input until EOF, which is indicated
	// as NULL by fgets, is provided by the user
          char clear[100];
          if (fgets(clear, 99, stdin) == NULL) {
              break;
          }
	// set the array storing the shifted characters to null after each iteration
	// so that we don't have remnant data from previous iterations
          memset(shifted,'\0',printf("%s\n", shifter(clear, shift)));
        }
	// keep looping until specified by the user. this could be dangerous if the user
	// does not know how to indicate that they ran out of inputs
        while (1);
}
