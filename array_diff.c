/*
array_diff.c

Exercício do CodeWars

Your goal in this kata is to implement a difference function,
which subtracts one list from another and returns the result.

It should remove all values from list a, which are present in list b.

array_diff({1, 2}, 2, {1}, 1, *z) == {2} (z == 1)

If a value is present in b, all of its occurrences must be removed from the other:

array_diff({1, 2, 2, 2, 3}, 5, {2}, 1, *z) == {1, 3} (z == 2)

size_t:

It’s a type which is used to represent the size of objects in bytes and is therefore
used as the return type by the sizeof operator. It is guaranteed to be big enough
to contain the size of the biggest object the host system can handle.
Basically the maximum permissible size is dependent on the compiler; if the compiler
is 32 bit then it is simply a typedef(i.e., alias) for unsigned int but if the compiler
is 64 bit then it would be a typedef for unsigned long long.
The size_t data type is never negative.
Therefore many C library functions like malloc, memcpy and strlen declare their
arguments and return type as size_t.

Fonte: https://www.geeksforgeeks.org/size_t-data-type-c-language/ 
*/

#include <stdio.h>
#include <stdlib.h>

int *array_diff(const int *arr1, int n1, const int *arr2, int n2, int *z);

int main(){
	//int a1[2] = {1,2};
	//int a2[1] = {1};
	
	//int a1[5] = {1, 2, 2, 2, 3};
	//int a2[1] = {2};
	
	//int a1[3] = {1,2,2};
	//int a2[1] = {1};

	//int a1[3] = {1,2,2};
	//int a2[1] = {};
	
	//int a1[3] = {1,2,2};
	//int a2[0] = {};	
	
	//int a1[0] = {};
	//int a2[2] = {1,2};	
	
	int a1[5] = {1,2,3,4,5};
	int a2[3] = {1,3,4};	

	
	int result[3] = {0};
	int *t;
	int *r;
	int i;
	
	r = array_diff(a1,5,a2,3,result);
    
    printf("%d \n",*r);

	for(i=0;i<*r;i++){
        printf("%d ",result[i]); 
	}
    
	return 0;
}

int *array_diff(const int *arr1, int n1, const int *arr2, int n2, int *z) {    
    int nr=0;
    int c = 0;
    int exist = 0;
    int i,j;
    int *index;    
    
    for(i=0;i<n1;i++){
        c = arr1[i];
        for(j=0;j<n2;j++){
      	    if(c == arr2[j]) exist=1;
	    }
	    if(!exist){  
	        z[nr] = c;    
	        nr++;     
	    }
	    exist=0;
    }
    index = &nr;    
    return index;    
}
