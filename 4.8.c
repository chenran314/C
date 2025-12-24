#include <stdio.h>
#include "module.h"

int main()
{
	int a=func1();
	int b=func2();
	printf("func1=%d,func2=%d,全局=%d",a,b,g_magic_number);

	return 0;
}

