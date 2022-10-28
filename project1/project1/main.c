#include <stdio.h>
#include <stdlib.h>


void fun(char s[], char c)
{
	char* p = s;
	printf("%p\n", s);
	for ( ;*p; p++)
	{
		if (*p != c) *(s++) = *p;//s++，所以在最后的时候是不需要再加1了。
	}
	*s = 0;//给s的最后一个元素放一个\0.
}


int main()
{
	char str[] = "turbo c and borland c++";
	printf("%p\n", str);
	fun(&str, 'c');//传值的方式，不是传址。
	printf("str[]=%s", str);
	return 0;
}



