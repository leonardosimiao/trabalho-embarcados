/*
 ============================================================================
 Name    	: code brake bias.c
 Author  	:
 Version 	: 1
 Copyright   : Your copyright notice
 Description : Code of the brake bias
 ============================================================================
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// quando 30, districuiçao 30-70(30 diant, 70 tras)
// quando 70, districuiçao 70-30(70 diant, 30 tras)
int analog_to_bcd(lin) { 
			n_11 = fn_11(lin);
			n_12 = fn_12(lin);
			n_13 = fn_13(lin);
			n_14 = fn_14(lin);
			n_21 = fn_21(lin);			
			n_22 = fn_22(lin);
			n_23 = fn_23(lin);
			n_24 = fn_24(lin);
			fwrite (n_11, 1, sizeof(n_11), bcd_11); 
			fwrite (n_12, 1, sizeof(n_12), bcd_12); 
			fwrite (n_13, 1, sizeof(n_13), bcd_13);
			fwrite (n_14, 1, sizeof(n_14), bcd_14); 			
			fwrite (n_21, 1, sizeof(n_21), bcd_21); 
			fwrite (n_22, 1, sizeof(n_22), bcd_22); 
			fwrite (n_23, 1, sizeof(n_23), bcd_23); 
			fwrite (n_24, 1, sizeof(n_24), bcd_24); 
			
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

int fn_11 (num){
	int a = unidade (num);
	int b = a%2;
	if (b==1){
		return 1;
	} else {
		return 0;
	}
}	

int fn_12 (num){
	int a = unidade (num);
	if (a==2 || a==3; || a==6; || a==7){
		return 1;
	} else {
		return 0;
	}	
}
	
int fn_13 (num){
	int a = unidade (num);
	if (a==4||a==5||a==6||a=7){
		return 1;
	}else{
		return 0;
	}
}

int fn_14 (num) {
	a = unidade (num);
	if (a==8||a==9){
		return 1;
	} else {
		return 0;
	}
}

int fn_21 (num){
	int a = dezena (num);
	int b = a%2;
	if (b==1){
		return 1;
	} else {
		return 0;
	}
}	

int fn_22 (num){
	int a = dezena (num);
	if (a==2 || a==3; || a==6; || a==7){
		return 1;
	} else {
		return 0;
	}	
}
	
int fn_23 (num){
	int a = dezena (num);
	if (a==4||a==5||a==6||a=7){
		return 1;
	}else{
		return 0;
	}
}

int fn_24 (num) {
	a = dezena (num);
	if (a==8||a==9){
		return 1;
	} else {
		return 0;
	}
}

int f_ang (num){
	int a = num/1000;
	a = 30 + 40*a
}

int f_lin (num){
	int a = num/1000;
	a = 30 + 40*a
}

int main() {
//    FILE *export_file = NULL;
    FILE *mot1 = NULL;
    FILE *mot2 = NULL;
    FILE *f_ang = NULL;
    FILE *f_lin = NULL;
    FILE *bcd_11 = NULL;
    FILE *bcd_12 = NULL;
    FILE *bcd_13 = NULL;
	FILE *bcd_14 = NULL;
    FILE *bcd_21 = NULL;
    FILE *bcd_22 = NULL;
	FILE *bcd_23 = NULL;
	FILE *bcd_24 = NULL;
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
	bcd_14 = fopen("/sys/class/gpio/gpio86/value","w");
	bcd_21 = fopen("/sys/class/gpio/gpio37/value","w");
	bcd_22 = fopen("/sys/class/gpio/gpio33/value","w");
	bcd_23 = fopen("/sys/class/gpio/gpio61/value","w");
	bcd_24 = fopen("/sys/class/gpio/gpio88/value","w");
	ang = f_ang(s_ang); //podem assumir valores entre 30 e 70
	lin = f_lin(s_lin); //pode assumir valores entre 30 e 70


while (1!=0){
	if (ang > lin){
		while (ang > lin) {
			fwrite (off, 1, sizeof(off), mot1);
			fwrite (on, 1, sizeof(on), mot2);
			analog_to_bcd (lin);
		}
	} else { 
		if {ang < lin) {
			while (ang < lin) {
				fwrite (on, 1, sizeof(on), mot1);
				fwrite (off, 1, sizeof(off), mot2);
				analog_to_bcd (lin);
			}
		} else {
			if (ang == lin){
				fwrite (off, 1, sizeof(off), mot1);
				fwrite (off, 1, sizeof(off), mot2);
				analog_to_bcd (lin);
			}
		}
}/*
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
