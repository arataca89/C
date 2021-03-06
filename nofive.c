/*
nofive.c

arataca89@gmail.com

CodeWars exercise:

In this kata you get the start number and the end number of a region
and should return the nr of all numbers except numbers with
a 5 in it. The start and the end number are both inclusive!

Examples:

1,9 -> 1,2,3,4,6,7,8,9 -> Result 8
4,17 -> 4,6,7,8,9,10,11,12,13,14,16,17 -> Result 12

The result may contain fives. ;-)
The start number will always be smaller than the end number.
Both numbers can be also negative!

*/

#include <stdio.h>
#include <string.h>

int dontGiveMeFive(int start, int end);


int main(){
	int i;
	//dontGiveMeFive(4,17);
	//dontGiveMeFive(4,29);
	//dontGiveMeFive(-30,17);	
	i = dontGiveMeFive(1,90);	
	printf("%d\n",i);
	return 0;
}


int dontGiveMeFive(int start, int end){
	int nr;
	int c=0;//counter
	char buff[50];
	
	for(nr=start;nr<=end;nr++ ){
		sprintf(buff,"%d",nr);
		if(!strchr(buff,'5')) c++;
	}
  return c;
}
/* end of nofive.c */
