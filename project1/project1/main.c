#include <stdio.h>
#include <stdlib.h>


void fun(char s[], char c)
{
	char* p = s;
	printf("%p\n", s);
	for ( ;*p; p++)
	{
		if (*p != c) *(s++) = *p;//s++������������ʱ���ǲ���Ҫ�ټ�1�ˡ�
	}
	*s = 0;//��s�����һ��Ԫ�ط�һ��\0.
}


int main()
{
	char str[] = "turbo c and borland c++";
	printf("%p\n", str);
	fun(&str, 'c');//��ֵ�ķ�ʽ�����Ǵ�ַ��
	printf("str[]=%s", str);
	return 0;
}



