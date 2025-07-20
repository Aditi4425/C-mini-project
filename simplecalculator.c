#include<stdio.h>
int main()
{
	int num1,num2,operation;
	printf("Choose one of the following options:");
	printf("\n1. Add");
	printf("\n2. Substract");
	printf("\n3.	Multiply");
	printf("\n4. Divide");
	printf("\n5. Modulus");
	printf("\n6. Power");
	printf("\n7. Exit");
	printf("Enter first numbers");
	scanf("%d",&num1);
	printf("Enter second numbers");
	scanf("%d",&num2);
	printf("Choose operation");
	scanf("%d",&operation);
	do
	{
		if(operation=1)
		{
			printf(%d+%d,num1 num2);
		}
		elseif(operation=2)
		{
			printf(%d-%d,num1 num2);
		}
		elseif(operation=3)
		{
			printf(%d*%d,num1 num2);
		}
		elseif(operation=4)
		{
			printf(%d/%d,num1 num2);
		}
		else(operation=5)
		{
			printf(%d%%d,num1 num2);
		}	
	}
	while(operation=7);
	return 0;	
}
	
