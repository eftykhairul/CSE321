
#include <stdio.h>

float multiplication(float i,float j)
{
    return i*j;
}

float subtraction(float i,float j)
{
    return i-j;
}

float addition(float i,float j)
{
	return i+j;
}

int main()
{
	float x,y;
	
	printf("Input first number: ");
	scanf("%f", &x);
	printf("Input second number: ");
	scanf("%f", &y);
	
	if (x > y)
    {
        printf("Subtraction: %.3f\n", subtraction(x,y));
    }
    else if (x < y)
    {
        printf("Addition: %.3f\n", addition(x,y));
    }
    else if (x == y)
    {
        printf("Multiplication: %.3f\n", multiplication(x,y));
    }
    
    return 0;

}