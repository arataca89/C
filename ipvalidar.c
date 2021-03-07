/*
ipvalidar.c

arataca89@gmail.com

CodeWars exercise:

Write an algorithm that will identify valid IPv4 addresses
in dot-decimal format. IPs should be considered valid if they consist
of four octets, with values between 0 and 255, inclusive.


Every computer connected to the Internet is identified by a unique
four-part string, known as its Internet Protocol (IP) address.
An IP address consists of four numbers (each between 0 and 255)
separated by periods. The format of an IP address is a 32-bit numeric
address written as four decimal numbers (called octets) separated by
periods; each number can be written as 0 to 255
(e.g., 0.0.0.0 to 255.255.255.255).

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int is_valid_ip(const char * addr);
int check(char *s);


int main(){
	char ip[]="174.74.16.9";
	//char ip[]="236.129.99.1";
	//char ip[]="144.127.72.171";
	//char ip[]="4.167.95.116";
	//char ip[]="199.179.32.127";
	//char ip[]="166.211.55.238";
	//char ip[]="45.90.154.101";
	//char ip[]="157.230.36.148";
	//char ip[]="124.43.12.211";
	//char ip[]="116.108.11.1";
	//char ip[]="174.74.16.9";
	//char ip[]="88.121.220.124";
	//char ip[]="242.190.245.83";
	//char ip[]="164.152.163.86";
	//char ip[]="1.2.3.4.5";
	//char ip[]="12.34.56";
	//char ip[]="123.1.67.255";
	int i;	
	i = is_valid_ip(ip); 	
	printf("%d\n",i);
	return 0;
}

/* Return 1 is addr is a valid IP address, return 0 otherwise */
int is_valid_ip(const char * addr) {
    char buff[4];
    int i = 0;
    size_t c;
    int ok = 1;
    int p = 0;
    
    for(c=0;c<strlen(addr);c++){   		
    	if(addr[c] == '.'){
    		p++;    		
			buff[i] = '\0';
            if(check(buff)){
                ok=1;
			}
			else{
				return 0;
			}
			for(i=0;i<=4;i++) buff[i]='\0';
			i=0;	
		} 
		else{
	   		if(!isdigit(addr[c])) return 0;
			buff[i++] = addr[c];
		} 
	}
    if(check(buff)){
        ok=1;
    }
	else{
		return 0;
	}  
	
	if(p!=3) return 0;
	
	return 1;

}


int check(char *s){
	int n = atoi(s);
	
	if(s[0] == '0' && s[1] == '0'){
	    return 0;
	}
	else
	if(s[0] == '0'){
		return 0;
	}
	
	if(n){
		if(n>=0 && n<=255){
			return 1;
		}
		else{
			return 0;
		}
	}
    else{
	    return 0;
	}
}
/* end of ipvalidar.c */
