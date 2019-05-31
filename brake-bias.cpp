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


// quando 30, distribuiçao 30-70(30 diant, 70 tras)
// quando 70, distribuiçao 70-30(70 diant, 30 tras)
int unidade (float num){
	int a = num;
	int b = a%10;
	return b;
}

int dezena (float num){
	int a = num;
	int b = a/10;
	return b;
}
char fn_11 (float num){
	int a = unidade (num);
	int b = a%2;
	if (b==1){
		return '1';
	} else {
		return '0';
	}
}

char fn_12 (float num){
	int a = unidade (num);
	if (a==2 || a==3 || a==6 || a==7){
		return '1';
	} else {
		return '0';
	}
}

char fn_13 (float num){
	int a = unidade(num);
	if (a==4 || a==5 || a==6 || a==7){
		return '1';
	}else{
		return '0';
	}
}

char fn_14 (float num) {
	int a = unidade(num);
	if (a==8 || a==9){
		return '1';
	} else {
		return '0';
	}
}

char fn_21 (float num){
	int a = dezena (num);
	int b = a%2;
	if (b==1){
		return '1';
	} else {
		return '0';
	}
}

char fn_22 (float num){
	int a = dezena (num);
	if (a==2 || a==3 || a==6 || a==7){
		return '1';
	} else{
		return '0';
	}
}

char fn_23 (float num){
	int a = dezena (num);
	if (a==4|| a==5 || a==6 || a==7){
		return '1';
	}else{
		return '0';
	}
}

char fn_24 (float num) {
	int a = dezena(num);
	if (a==8 || a==9){
		return '1';
	} else {
		return '0';
	}
}

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

int analog_to_bcd(float lin) {
	char n_11[1], n_12[1], n_13[1], n_14[1], n_21[1], n_22[1], n_23[1], n_24[1];
	n_11[0] = fn_11(lin);
	n_12[0] = fn_12(lin);
	n_13[0] = fn_13(lin);
	n_14[0] = fn_14(lin);
	n_21[0] = fn_21(lin);
	n_22[0] = fn_22(lin);
	n_23[0] = fn_23(lin);
	n_24[0] = fn_24(lin);
	FILE *bcd_11 = NULL;
	FILE *bcd_12 = NULL;
	FILE *bcd_13 = NULL;
	FILE *bcd_14 = NULL;
	FILE *bcd_21 = NULL;
	FILE *bcd_22 = NULL;
	FILE *bcd_23 = NULL;
	FILE *bcd_24 = NULL;
	bcd_11 = fopen("/sys/class/gpio/gpio30/value","w"); //P9.11
	bcd_12 = fopen("/sys/class/gpio/gpio31/value","w"); //P9.13
	bcd_13 = fopen("/sys/class/gpio/gpio48/value","w"); //P9.15
	bcd_14 = fopen("/sys/class/gpio/gpio49/value","w"); //P9.23
	bcd_21 = fopen("/sys/class/gpio/gpio60/value","w"); //P9.12
	bcd_22 = fopen("/sys/class/gpio/gpio50/value","w"); //P9.14
	bcd_23 = fopen("/sys/class/gpio/gpio51/value","w"); //P9.16
	bcd_24 = fopen("/sys/class/gpio/gpio15/value","w"); //P9.24
	fwrite (n_11, sizeof(char), 1, bcd_11);
	fwrite (n_12, sizeof(char), 1, bcd_12);
	fwrite (n_13, sizeof(char), 1, bcd_13);
	fwrite (n_14, sizeof(char), 1, bcd_14);
	fwrite (n_21, sizeof(char), 1, bcd_21);
	fwrite (n_22, sizeof(char), 1, bcd_22);
	fwrite (n_23, sizeof(char), 1, bcd_23);
	fwrite (n_24, sizeof(char), 1, bcd_24);
	usleep(10000);
	fclose (bcd_11);
	fclose (bcd_12);
	fclose (bcd_13);
	fclose (bcd_14);
	fclose (bcd_21);
	fclose (bcd_22);
	fclose (bcd_23);
	fclose (bcd_24);
	return 0;
}

int main() {

/*	//Configuração inicial das portas >> realizada em codigo proprio

	// configurar entradas analógicas (necessita rodar como root)
	system("echo BB-ADC > /sys/devices/platform/bone_capemgr/slots");

	// habilitar portas do motor
	system("echo 66 > /sys/class/gpio/export");
	system("echo 67 > /sys/class/gpio/export");
	system("echo 68 > /sys/class/gpio/export");

	// habilitar portas do display
	system("echo 30 > /sys/class/gpio/export");
	system("echo 31 > /sys/class/gpio/export");
	system("echo 48 > /sys/class/gpio/export");
	system("echo 49 > /sys/class/gpio/export");
	system("echo 60 > /sys/class/gpio/export");
	system("echo 50 > /sys/class/gpio/export");
	system("echo 51 > /sys/class/gpio/export");
	system("echo 15 > /sys/class/gpio/export");

	// configurando portas do motor como saídas
	system("echo out > /sys/class/gpio/gpio66/direction");
	system("echo out > /sys/class/gpio/gpio67/direction");
	system("echo out > /sys/class/gpio/gpio68/direction");

	system("echo 1 > /sys/class/gpio/gpio68/value"); // enabler do motor -> sempre definido como 1

	// configurando portas do motor como saídas
	system("echo out > /sys/class/gpio/gpio30/direction");
	system("echo out > /sys/class/gpio/gpio31/direction");
	system("echo out > /sys/class/gpio/gpio48/direction");
	system("echo out > /sys/class/gpio/gpio49/direction");
	system("echo out > /sys/class/gpio/gpio60/direction");
	system("echo out > /sys/class/gpio/gpio50/direction");
	system("echo out > /sys/class/gpio/gpio51/direction");
	system("echo out > /sys/class/gpio/gpio15/direction");
*/
//    FILE *export_file = NULL;
    FILE *mot1 = NULL;
    FILE *mot2 = NULL;
    FILE *f_ang = NULL;
    FILE *f_lin = NULL;
    char on[] = "1";
    char off[] = "0";

	int s_ang;
	int s_lin;

	char c_ang[7];
	char c_lin[7];

	//ground ADC -----------------------------------------------------------  P9.34
	//vcc ADC --------------------------------------------------------------  P9.32
	f_ang = fopen("/sys/bus/iio/devices/iio:device0/in_voltage1_raw", "r"); //P9.40
	f_lin = fopen("/sys/bus/iio/devices/iio:device0/in_voltage0_raw", "r"); //P9.39

	fread(c_ang, sizeof(char), 6, f_ang);
	s_ang = strtol(c_ang,NULL,0);
	fread(c_lin, sizeof(char), 6, f_lin);
	s_lin = strtol(c_lin,NULL,0);

	fclose(f_ang);
	fclose(f_lin);


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
			mot1 = fopen("/sys/class/gpio/gpio66/value", "w"); // P8.7
			mot2 = fopen("/sys/class/gpio/gpio67/value", "w"); // P8.8
			// enabler = fopen("/sys/class/gpio/gpio68/value", "w"); // P8.10 --> sempre definido como 1
			fwrite (off, sizeof(char), 1, mot1);
			fwrite (on, sizeof(char), 1, mot2);
			usleep(10000);
			fclose(mot2);
			fclose(mot1);
			analog_to_bcd (lin);
	}
	else {
		if (ang < lin){
			mot1 = fopen("/sys/class/gpio/gpio66/value", "w");
			mot2 = fopen("/sys/class/gpio/gpio67/value", "w");
			fwrite (on, sizeof(char), 1, mot1);
			fwrite (off, sizeof(char), 1, mot2);
			usleep(10000);
			fclose(mot2);
			fclose(mot1);
			analog_to_bcd (lin);
		}
		else {
			if (ang == lin){
				mot1 = fopen("/sys/class/gpio/gpio66/value", "w");
				mot2 = fopen("/sys/class/gpio/gpio67/value", "w");
				fwrite (off, sizeof(char), 1, mot1);
				fwrite (off, sizeof(char), 1, mot2);
				usleep(10000);
				fclose(mot2);
				fclose(mot1);
				analog_to_bcd (lin);
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
