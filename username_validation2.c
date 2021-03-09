/*
username_validation2.c

arataca89@gmail.com

coderbyte exercise:

CodelandUsernameValidation(str) take the str parameter being passed
and determine if the string is a valid username according to the
following rules:

1. The username is between 4 and 25 characters.
2. It must start with a letter.
3. It can only contain letters, numbers, and the underscore character.
4. It cannot end with an underscore character.

If the username is valid then your program should return the string
true, otherwise return the string false.

Examples
Input: "aa_"
Output: false
Input: "u__hello_world123"
Output: true

*/

#include <stdio.h> 
#include <string.h>
#include <ctype.h>


void CodelandUsernameValidation(char str[]) {
  
  int i;  
  int size = strlen(str);
  char *buff = "true";
  
  if(size<4 || size>25)
     buff="false";
  
  if( !isalpha(str[0]) )
    buff="false";
    
  for(i=0;i<size;i++){
  	
  	if(i==size-1){
  		if(str[i]=='_')
		    buff="false";
	  }
  	    
  	if( isalnum(str[i]) || str[i]=='_'){
  	    ;    	   
	}
	else{
		buff="false";
	}
  }
  
  printf("%s", buff);
}


int main(void) { 

   
   CodelandUsernameValidation("123");
   CodelandUsernameValidation("12345678901234567890123456");   
   CodelandUsernameValidation("1u__hello_world123");
   CodelandUsernameValidation("u__hell$o_world123");
   CodelandUsernameValidation("u__hello_world123_");
   CodelandUsernameValidation("u__hello_world123");

  // keep this function call here
  //CodelandUsernameValidation(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}


/* end of username_validation2.c */
