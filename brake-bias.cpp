//============================================================================
// Name        : brake-bias.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

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
/*int unidade (float num){
	int a, b = 0;
	a = num/1;
	b = a%10;
	return b;
}

int dezena (float num){
	int a, b = 0;
	a = num/1;
	b = a/10;
	return b;
}*/
/*
int fn_11 (float num){
	int a = unidade (num);
	int b = a%2;
	if (b==1){
		return 1;
	} else {
		return 0;
	}
}

int fn_12 (float num){
	int a = unidade (num);
	if (a==2 || a==3 || a==6 || a==7){
		return 1;
	} else {
		return 0;
	}
}

int fn_13 (float num){
	int a = unidade(num);
	if (a==4 || a==5 || a==6 || a==7){
		return 1;
	}else{
		return 0;
	}
}

int fn_14 (float num) {
	int a = unidade(num);
	if (a==8 || a==9){
		return 1;
	} else {
		return 0;
	}
}

int fn_21 (float num){
	int a = dezena (num);
	int b = a%2;
	if (b==1){
		return 1;
	} else {
		return 0;
	}
}

int fn_22 (float num){
	int a = dezena (num);
	if (a==2 || a==3 || a==6 || a==7){
		return 1;
	} else{
		return 0;
	}
}

int fn_23 (float num){
	int a = dezena (num);
	if (a==4|| a==5 || a==6 || a=7){
		return 1;
	}else{
		return 0;
	}
}

int fn_24 (float num) {
	int a = dezena(num);
	if (a==8 || a==9){
		return 1;
	} else {
		return 0;
	}
}
*/
int fun_ang (float num){
	int a = num/409;
	a = 30 + 4*a;
	return a;
}

int fun_lin (float num){
	int a = num/409;
	a = 30 + 4*a;
	return a;
}
/*
int analog_to_bcd(float lin) {
			int n_11 = fn_11(lin);
			int n_12 = fn_12(lin);
			int n_13 = fn_13(lin);
			int n_14 = fn_14(lin);
			int n_21 = fn_21(lin);
			int n_22 = fn_22(lin);
			int n_23 = fn_23(lin);
			int n_24 = fn_24(lin);
			fwrite (n_11, 1, sizeof(n_11), bcd_11);
			fwrite (n_12, 1, sizeof(n_12), bcd_12);
			fwrite (n_13, 1, sizeof(n_13), bcd_13);
			fwrite (n_14, 1, sizeof(n_14), bcd_14);
			fwrite (n_21, 1, sizeof(n_21), bcd_21);
			fwrite (n_22, 1, sizeof(n_22), bcd_22);
			fwrite (n_23, 1, sizeof(n_23), bcd_23);
			fwrite (n_24, 1, sizeof(n_24), bcd_24);
}
*/

int main() {
//    FILE *export_file = NULL;
    FILE *mot1 = NULL;
    FILE *mot2 = NULL;
    FILE *f_ang = NULL;
    FILE *f_lin = NULL;
/*  FILE *bcd_11 = NULL;
    FILE *bcd_12 = NULL;
    FILE *bcd_13 = NULL;
  	FILE *bcd_14 = NULL;
    FILE *bcd_21 = NULL;
    FILE *bcd_22 = NULL;
  	FILE *bcd_23 = NULL;
  	FILE *bcd_24 = NULL;*/
    char on[] = "1";
    char off[] = "0";

	int s_ang;
	int s_lin;

	char c_ang[7];
	char c_lin[7];

	f_ang = fopen("/sys/bus/iio/devices/iio:device0/in_voltage1_raw", "r");
	f_lin = fopen("/sys/bus/iio/devices/iio:device0/in_voltage0_raw", "r");

	fread(c_ang, sizeof(char), 6, f_ang);
	s_ang = strtol(c_ang,NULL,0);
	fread(c_lin, sizeof(char), 6, f_lin);
	s_lin = strtol(c_lin,NULL,0);

	fclose(f_ang);
	fclose(f_lin);

	/*bcd_11 = fopen("/sys/class/gpio/gpio62/value","w");
	bcd_12 = fopen("/sys/class/gpio/gpio36/value","w");
	bcd_13 = fopen("/sys/class/gpio/gpio32/value","w");
	bcd_14 = fopen("/sys/class/gpio/gpio86/value","w");
	bcd_21 = fopen("/sys/class/gpio/gpio37/value","w");
	bcd_22 = fopen("/sys/class/gpio/gpio33/value","w");
	bcd_23 = fopen("/sys/class/gpio/gpio61/value","w");
	bcd_24 = fopen("/sys/class/gpio/gpio88/value","w");*/
	int ang = fun_ang(s_ang); //podem assumir valores entre 30 e 70
	int lin = fun_lin(s_lin); //pode assumir valores entre 30 e 70


while (1!=0){

	f_ang = fopen("/sys/bus/iio/devices/iio:device0/in_voltage1_raw", "r");
	fread(c_ang, sizeof(char), 6, f_ang);
	s_ang = strtol(c_ang,NULL,0);

	f_lin = fopen("/sys/bus/iio/devices/iio:device0/in_voltage0_raw", "r");
	fread(c_lin, sizeof(char), 6, f_lin);
	s_lin = strtol(c_lin,NULL,0);

	ang = fun_ang(s_ang); //podem assumir valores entre 30 e 70
	lin = fun_lin(s_lin); //pode assumir valores entre 30 e 70

	printf("ang: %d lin %d \n", ang,lin);

	if (ang > lin){
			mot1 = fopen("/sys/class/gpio/gpio66/value", "w");
			mot2 = fopen("/sys/class/gpio/gpio67/value", "w");
			fwrite (off, sizeof(char), 1, mot1);
			fwrite (on, sizeof(char), 1, mot2);
			usleep(1000000);
			fclose(mot2);
			fclose(mot1);
			//analog_to_bcd (lin);
	}
	else {
		if (ang < lin){
			mot1 = fopen("/sys/class/gpio/gpio66/value", "w");
			mot2 = fopen("/sys/class/gpio/gpio67/value", "w");
			fwrite (on, sizeof(char), 1, mot1);
			fwrite (off, sizeof(char), 1, mot2);
			usleep(1000000);
			fclose(mot2);
			fclose(mot1);
			//analog_to_bcd (lin);
		}
		else {
			if (ang == lin){
				mot1 = fopen("/sys/class/gpio/gpio66/value", "w");
				mot2 = fopen("/sys/class/gpio/gpio67/value", "w");
				fwrite (off, sizeof(char), 1, mot1);
				fwrite (off, sizeof(char), 1, mot2);
				usleep(1000000);
				fclose(mot2);
				fclose(mot1);
				//analog_to_bcd (lin);
			}
		}
	}
	fclose(f_ang);
	fclose(f_lin);
}
fclose(f_ang);
fclose(f_lin);
fclose(mot2);
fclose(mot1);
}
