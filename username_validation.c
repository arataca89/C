/*
username_validation.c

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


char* CodelandUsernameValidation(char str[]) {
  
  int i;  
  int size = strlen(str);
  
  if(size<4 || size>25)
     return "false";
  
  if( !isalpha(str[0]) )
    return "false";
    
  for(i=0;i<size;i++){
  	
  	if(i==size-1){
  		if(str[i]=='_')
		    return "false";
	  }
  	    
  	if( isalnum(str[i]) || str[i]=='_'){
  	    ;    	   
	}
	else{
		return "false";
	}
  }
  
  return "true";
}


int main(void) { 

  char str[] = "u__hello_world123";
  //char str[] = "1234567890123456789012345";
  
  printf("%s\n",CodelandUsernameValidation(str));
   
  // keep this function call here
  //CodelandUsernameValidation(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}


/* end of username_validation.c */
