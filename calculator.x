struct numbers{
	float a;
	float b;
	char sign;
};

struct numbers1{
	float aa;
	float bb;
	char sign;
};

program CALCULATOR_PROG{
	/*Version 1: Un-rounded result*/
	version CALCULATOR_VERS{
		float add(numbers)=1;
		float sub(numbers)=2;
		float mul(numbers)=3;
		float div(numbers)=4;
	}=1;

	/*Version 2: Rounded result*/
	version CALCULATOR_VERS1{
		float add(numbers1)=1;
		float sub(numbers1)=2;
		float mul(numbers1)=3;
		float div(numbers1)=4;
	}=2;
}=0x23451111;
