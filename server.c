#include <rpc/rpc.h>
#include "calculator.h"
#include <math.h>

/*Version 1: Un-rounded result*/
//addition
float * add_1_svc(numbers *argp, struct svc_req *rqstp)
{
	static float result;
	printf("add(%f, %f) is called\n", argp->a, argp->b);
	result = argp->a+argp->b;
	return &result;
}

//subtraction
float * sub_1_svc(numbers *argp, struct svc_req *rqstp)
{
	static float result;
	printf("sub(%f, %f) is called\n", argp->a, argp->b);
	result = argp->a-argp->b;
	return &result;
}

//multiplication
float * mul_1_svc(numbers *argp, struct svc_req *rqstp)
{
	static float result;
	printf("mul(%f, %f) is called\n", argp->a, argp->b);
	result = argp->a*argp->b;
	return &result;
}

//division
float * div_1_svc(numbers *argp, struct svc_req *rqstp)
{
	static float result;
	printf("div(%f, %f) is called\n", argp->a, argp->b);
	result = argp->a/argp->b;
	return &result;
}




/*Version 2: The rounded result*/
//addition
float * add_2_svc(numbers1 *argp, struct svc_req *rqstp)
{
	static float result;
	result = result + 0.5;
	result = (int)result;
	printf("add(%f, %f) is called\n", argp->aa, argp->bb);
	result = argp->aa+argp->bb;
	return &result;
}

//subtraction
float * sub_2_svc(numbers1 *argp, struct svc_req *rqstp)
{
	static float result;
	result = result + 0.5;
	result = (int)result;
	printf("sub(%f, %f) is called\n", argp->aa, argp->bb);
	result = argp->aa-argp->bb;
	return &result;
}

//multiplication
float * mul_2_svc(numbers1 *argp, struct svc_req *rqstp)
{
	static float result;
	result = result + 0.5;
	result = (int)result;
	printf("mul(%f, %f) is called\n", argp->aa, argp->bb);
	result = argp->aa*argp->bb;
	return &result;
}

//division
float * div_2_svc(numbers1 *argp, struct svc_req *rqstp)
{
	static float result;
	result = result + 0.5;
	result = (int)result;
	printf("div(%f, %f) is called\n", argp->aa, argp->bb);
	result = argp->aa/argp->bb;
	return &result;
}



