#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "head.h"


int main(void)
{
	int num;
	bool flag = 0;
	printf("������һ�������ж��ǲ��ǻ�����\n");
	scanf("%d", &num);
	flag = isPalindrome(num);
	printf("%d", flag);
}