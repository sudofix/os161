#include <types.h>
#include <lib.h>
#include <info.h>
void info()
{
	kprintf("Os161 By Mohamed Ramadan, 17108770");
}
void calculator()
{

	kprintf("\n\n");
	char operator[10];
	char firstt[10];
	char secondd[10];
	kprintf("Enter an operator (+, -, *,) or 'x' to exit: \n");
	kgets(operator, sizeof(operator));
	while (operator[0] != 'x')
	{
		kprintf("Enter two operands: \n");
		kgets(firstt, sizeof(firstt));
		kgets(secondd, sizeof(secondd));
		//-----------------------------
		//kprintf("%d",sizeof(firstt));
		//kprintf("\n");
		//kprintf("%d",sizeof(firstt));
		//kprintf("\n");
		char c;
		unsigned int i;
		int digit, first = 0, second = 0;
		for (i = 0; i < sizeof(firstt) / sizeof(firstt[0]); i++)
		{
			c = firstt[i];
			if (c > '9' || c < '0')
				break;
			digit = c - '0';
			first = first * 10 + digit;
		}
		for (i = 0; i < sizeof(secondd) / sizeof(secondd[0]); i++)
		{
			c = secondd[i];
			if (c > '9' || c < '0')
				break;
			digit = c - '0';
			second = second * 10 + digit;
		}
		//-----------------------------
		switch (operator[0])
		{
		case '+':
			kprintf("%d + %d = %d", first, second, first + second);
			break;
		case '-':
			kprintf("%d - %d = %d", first, second, first - second);
			break;
		case '*':
			kprintf("%d * %d = %d", first, second, first * second);
			break;
		case '/':
			kprintf("%d / %d = %d", first, second, first / second);
			break;
		// operator doesn't match any case constant
		default:
			kprintf("Error! operator is not correct");
		}
		kprintf("\n");
		kprintf("Enter an operator (+, -, *,) or 'x' to exit: \n");
		kgets(operator, sizeof(operator));
	}
}
void about()
{
	kprintf("-------------------------\n");
	kprintf("|     Hi There!         |\n");
	kprintf("| I'm Mohamed Ramadan   |\n");
	kprintf("-------------------------\n");
}