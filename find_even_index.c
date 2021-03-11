/*
find_even_index.c

arataca89@gmail.com

CodeWars exercise:

You are going to be given an array of integers.
Your job is to take that array and find an index N where the sum of
the integers to the left of N is equal to the sum of the integers
to the right of N.
If there is no index that would make this happen, return -1.

For example:

Let's say you are given the array {1,2,3,4,3,2,1}:
Your function will return the index 3, because at the 3rd position of
the array, the sum of left side of the index ({1,2,3}) and the sum of
the right side of the index ({3,2,1}) both equal 6.

Let's look at another one.
You are given the array {1,100,50,-51,1,1}:
Your function will return the index 1, because at the 1st position of
the array, the sum of left side of the index ({1}) and the sum of the
right side of the index ({50,-51,1,1}) both equal 1.

Last one:
You are given the array {20,10,-80,10,10,15,35}
At index 0 the left side is {}
The right side is {10,-80,10,10,15,35}
They both are equal to 0 when added. 
(Empty arrays are equal to 0 in this problem)
Index 0 is the place where the left side and right side are equal.

Note: Please remember that in most programming/scripting languages
the index of an array starts at 0.

Input:
An integer array of length 0 < arr < 1000. The numbers in the array
can be any integer positive or negative.

Output:
The lowest index N where the side to the left of N is equal to the
side to the right of N. If you do not find an index that fits these
rules, then you will return -1.

Note:
If you are given an array with multiple answers, return the lowest
correct index.

*/

#include <stdio.h>

int find_even_index(const int *values, int length);

int main(){
	int r;
	//int n[7] = {1,2,3,4,3,2,1};// 3
    //int n[6] = {1,100,50,-51,1,1};// 1
    //int n[7] = {20,10,-80,10,10,15,35};// 0
    //int n[6] = {1,2,3,4,5,6}; // -1
    //int n[7] = {20,10,30,10,10,15,35};// 3 
	//int n[7] = {20,10,-80,10,10,15,35};// 0 
	//int n[7] = {10,-80,10,10,15,35,20};// 6
	//int n[5] = {0,0,0,0,0};// 0
	int n[7] = {-1,-2,-3,-4,-3,-2,-1};// 3
	r = find_even_index(n,7); // <=== AJUSTE AQUI PARA OS TESTES (a qtde de itens do array)
	
	printf("index: %d\n",r);
    return 0;
}

int find_even_index(const int *values, int length) {
	int i,j,t;
	int sum_pre=0, sum_pos=0;
		
	for(i=0;i<length;i++){
		
		if(i==0) sum_pre = 0;
		if(i==length) sum_pos = 0;
		
		for(j=0;j<i;j++){
	        sum_pre += values[j];				
		}

		for(t=(i+1);t<length;t++){
		    sum_pos += values[t];	
		}
	
		printf("sum_pre: %d - nr: %d - sum_pos: %d\n",sum_pre,values[i],sum_pos);
		
	    if(sum_pre == sum_pos){
	    	return i;
		}		
		
		sum_pre=0;
		sum_pos=0;
	}
    
    //printf("\n");
    //printf("indice: %d\n",index);
    
    return -1;
}

/* end of find_even_index.c */
