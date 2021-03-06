/*
array_diff.c

arataca89@gmail.com

Exercício do CodeWars:

Your goal in this kata is to implement a difference function,
which subtracts one list from another and returns the result.

It should remove all values from list a, which are present in list b.

array_diff({1, 2}, 2, {1}, 1, *z) == {2} (z == 1)

If a value is present in b, all of its occurrences must be removed from the other:

array_diff({1, 2, 2, 2, 3}, 5, {2}, 1, *z) == {1, 3} (z == 2)
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
