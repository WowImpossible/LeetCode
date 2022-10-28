#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "head.h"


int main(void)
{
	int num;
	bool flag = 0;
	printf("请输入一个数字判断是不是回文数\n");
	scanf("%d", &num);
	flag = isPalindrome(num);
	printf("%d", flag);
}