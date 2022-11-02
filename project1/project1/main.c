#include <stdio.h>
#include <stdlib.h>


void fun(char* s, char c)
{
	char* p = s;
	printf("%p\n", s);
	for ( ;*p; p++)
	{
		if (*p != c) *(s++) = *p;//s++，所以在最后的时候是不需要再加1了。
	}
	*s = 0;//给s的最后一个元素放一个\0.
}


void nihao(int a, int b)
{
	int temp;
	printf("%p\n", &a);
	printf("%p\n", &b);
	temp = a;
	a = b;
	b = temp;
}


int main()
{
	char str[] = "turbo c and borland c++";
	int a = 10;
	int b = 20;
	printf("%p\n", &a);
	printf("%p\n", &b);
	printf("%p\n", str);
	fun(str, 'c');//传值的方式，不是传址。
	nihao(10, 20);
	printf("str[]=%s", str);
	return 0;
}



