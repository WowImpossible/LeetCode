#include <stdio.h>
#include <stdlib.h>


void fun(char* s, char c)
{
	char* p = s;
	printf("%p\n", s);
	for ( ;*p; p++)
	{
		if (*p != c) *(s++) = *p;//s++������������ʱ���ǲ���Ҫ�ټ�1�ˡ�
	}
	*s = 0;//��s�����һ��Ԫ�ط�һ��\0.
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
	fun(str, 'c');//��ֵ�ķ�ʽ�����Ǵ�ַ��
	nihao(10, 20);
	printf("str[]=%s", str);
	return 0;
}



