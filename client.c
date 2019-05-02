#include <stdio.h>
#include <rpc/rpc.h>
#include "calculator.h"
#include <math.h>

/*Version 1: Un-rounded result*/
float calculator_prog_1(char *host, float x, float y, char sign1, CLIENT *clnt)
{
	float *result_1;
	numbers add_1_arg;
	
	float *result_2;
	numbers sub_1_arg;

	float *result_3;
	numbers mul_1_arg;

	float *result_4;	
	numbers div_1_arg;

	//Addition
	if (sign1=='+') {
		add_1_arg.a=x;
		add_1_arg.b=y;
		add_1_arg.sign=sign1;
		result_1 = add_1(&add_1_arg, clnt);
		if (result_1==(float *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		return *result_1;
	}

	//Subtraction
	else if (sign1=='-') {
		sub_1_arg.a=x;
		sub_1_arg.b=y;
		sub_1_arg.sign=sign1;
		result_2 = sub_1(&sub_1_arg, clnt);
		if (result_2==(float *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		return *result_2;
	}

	//Multiplication
	else if (sign1=='*') {
		mul_1_arg.a=x;
		mul_1_arg.b=y;
		mul_1_arg.sign=sign1;
		result_3 = mul_1(&mul_1_arg, clnt);
		if (result_3==(float *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		return *result_3;
	}

	//Division
	else if (sign1=='/') {
		div_1_arg.a=x;
		div_1_arg.b=y;
		div_1_arg.sign=sign1;
		result_4 = div_1(&div_1_arg, clnt);
		if (y==0) {
		printf("Numerator can not be 0 in division.\n");
		exit(0); 
		}
		else {
			if (result_4==(float *) NULL) {
				clnt_perror (clnt, "call failed");
			}
			return *result_4;
		}

	}
	//Not arithmetic operator
	else {
		printf("Not arithmetic operators including + - * / \n");
		exit(0);
	}
}



/*Version 2: Rounded result*/
float calculator_prog_2(char *host, float x, float y, char sign1, CLIENT *clnt)
{
	float *result_11;
	numbers1 add_2_arg;
	
	float *result_22;
	numbers1 sub_2_arg;

	float *result_33;
	numbers1 mul_2_arg;

	float *result_44;	
	numbers1 div_2_arg;

	//Addition
	if (sign1=='+') {
		add_2_arg.aa=x;
		add_2_arg.bb=y;
		add_2_arg.sign=sign1;
		result_11 = add_2(&add_2_arg, clnt);
		if (result_11==(float *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		return *result_11;
	}

	//Subtraction
	else if (sign1=='-') {
		sub_2_arg.aa=x;
		sub_2_arg.bb=y;
		sub_2_arg.sign=sign1;
		result_22 = sub_2(&sub_2_arg, clnt);
		if (result_22==(float *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		return *result_22;
	}

	//Multiplication
	else if (sign1=='*') {
		mul_2_arg.aa=x;
		mul_2_arg.bb=y;
		mul_2_arg.sign=sign1;
		result_33 = mul_2(&mul_2_arg, clnt);
		if (result_33==(float *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		return *result_33;
	}

	//Division
	else if (sign1=='/') {
		div_2_arg.aa=x;
		div_2_arg.bb=y;
		div_2_arg.sign=sign1;
		result_44 = div_2(&div_2_arg, clnt);
		if (y==0) {
		printf("Numerator can not be 0 in division.\n");
		exit(0); 
		}
		else {
			if (result_44==(float *) NULL) {
				clnt_perror (clnt, "call failed");
			}
			return *result_44;
		}

	}

	//Not arithemetic operators
	else {
		printf("Not arithmetic operators including + - * / \n");
		exit(0);
	}
}


int main (int argc, char *argv[])
{
CLIENT*clnt;
char *host;
float m, n;
char sign2;
int v;
if (argc < 2) {
	printf ("usage: %s server_host\n", argv[0]);
	exit (1);
	}

host = argv[1];
clnt = clnt_create(host, CALCULATOR_PROG, CALCULATOR_VERS, "udp");
if (clnt == NULL) {
	clnt_pcreateerror (host);
	exit(1);
}

/*read input from keyboard*/
//printf("Enter operand 1: \n");
//scanf("%f", &m);
//printf("Enter sign: \n");
//scanf("%s", &sign2);
//printf("Enter operand 2: \n");
//scanf("%f", &n);
//printf("The result is: %f \n", calculator_prog_1(host, m, n, sign2, clnt));

/*Read input from input file*/
printf("Enter the version number either 1 or 2: \n");
scanf("%d", &v);
FILE *pFile;
pFile = fopen("inputfile.txt", "r");
if (pFile != NULL)
{
	while (!feof(pFile))
	{
		fscanf(pFile, "%f %c %f", &m, &sign2, &n);
		printf("%f %c %f \n", m, sign2, n);

                if(v == 1)
                {
			printf("The un-rounded result is: %f \n", calculator_prog_1(host, m, n, sign2, clnt));
		}

		if(v == 2)
                {			
			printf("The rounded result is: %.0f \n", calculator_prog_2(host, m, n, sign2, clnt));
		}
               
	}
	fclose(pFile);
}
else
{
	printf("Could not open the file.\n");
	exit(1);
}

clnt_destroy (clnt);

exit (0);
}
