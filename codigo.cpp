/*
 ============================================================================
 Name    	: blink.c
 Author  	:
 Version 	:
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// quando 30, districuiçao 30-70(30 diant, 70 tras)
// quando 70, districuiçao 70-30(70 diant, 30 tras)
int analog_to_bcd(lin) { 
			fwrite (on, 1, sizeof(on), mot1);
			fwrite (on, 1, sizeof(on), mot2);
			n_11 = f(lin);
			n_12 = f(lin);
			n_13 = f(lin);
			n_21 = f(lin);			
			n_22 = f(lin);
			n_23 = f(lin);
			fwrite (n_11, 1, sizeof(n_11), bcd_11); 
			fwrite (n_12, 1, sizeof(n_12), bcd_12); 
			fwrite (n_13, 1, sizeof(n_13), bcd_13); 
			fwrite (n_21, 1, sizeof(n_21), bcd_21); 
			fwrite (n_22, 1, sizeof(n_22), bcd_22); 
			fwrite (n_23, 1, sizeof(n_23), bcd_23); 
}

int unidade (num){
	int a, b = 0;
	a = num/1;
	b = a%10;
	return b;	
}

int dezena (num){
	int a, b = 0;
	a = num/1;
	b = a/10;
	return b;
}
int n_11 (num){
	
	
}	

int main(void) {
//    FILE *export_file = NULL;
    FILE *mot1 = NULL;
    FILE *mot2 = NULL;
    FILE *f_ang = NULL;
    FILE *f_lin = NULL;
    FILE *bcd_11 = NULL;
    FILE *bcd_12 = NULL;
    FILE *bcd_13 = NULL;
    FILE *bcd_21 = NULL;
    FILE *bcd_22 = NULL;
	FILE *bcd_23 = NULL;
    char on[] = "1";
    char off[] = "0";
	mot1 = fopen("/sys/class/gpio/gpio66/value", "w");
	mot2 = fopen("/sys/class/gpio/gpio67/value", "w");
	f_ang = fopen("/sys/....", "r";
	s_ang = fread( 1, sizeof(on), f_ang);
	f_lin = fopen("/sys/...", "r");
	s_lin = fread( 1, sizeof(on), f_lin);
	bcd_11 = fopen("/sys/class/gpio/gpio62/value","w");
	bcd_12 = fopen("/sys/class/gpio/gpio36/value","w");
	bcd_13 = fopen("/sys/class/gpio/gpio32/value","w");
	bcd_21 = fopen("/sys/class/gpio/gpio37/value","w");
	bcd_22 = fopen("/sys/class/gpio/gpio33/value","w");
	bcd_23 = fopen("/sys/class/gpio/gpio61/value","w");
	ang = f(s_ang); //podem assumir valores entre 0 e 100
	lin = f(s_lin); //pode assumir valores entre 0 e 100


while (1!=0){
	if (ang > lin){
		while (ang > lin) {
			fwrite (on, 1, sizeof(on), mot1);
			fwrite (on, 1, sizeof(on), mot2);
			analog_to_bcd (lin);
		}
	} else { 
		if {ang < lin) {
			while (ang < lin) {
				fwrite (on, 1, sizeof(on), mot1);
				fwrite (on, 1, sizeof(on), mot2);
				analog_to_bcd (lin);
			}
		} else {
			if (ang == lin){
				fwrite (on, 1, sizeof(on), mot1);
				fwrite (on, 1, sizeof(on), mot2);
				analog_to_bcd (lin);
			}
		}
}