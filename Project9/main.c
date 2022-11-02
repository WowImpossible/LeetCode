#define _CRT_SECURE_NO_WARNINGS 1

//罗马数字转整数，题号13
//怎么说呢，就是按照哪几种特例将它例举出来就可以了，就还好，不是很难，好像对于Python来说会相对简单一点。

#include <stdio.h>

//题目描述：罗马数字转整数，罗马数只有I， V， X， L，C，D 和 M这几种，将其转化为整数就可以了。
//传入参数：s是要转换的字符串
//返回值：整数值      
//疑惑的点，之前函数内部设置的变量一出函数就会被销毁，但是现在却没有报错，不知道是什么原因。有没有可能是因为返回值的问题
//          可能如果返回的是地址的话就会报错，但是返回的是数值的话应该可以。但是最好就是不要这样写，不规范。
//注意的点：单引号是比较单个字符，双引号是表示字符串。


int romanToInt(char* s) {

	int sum = 0;
	char* p = s;
	char* m = s;
	int flag = 0;

	if ((*m == 'I') && (*(m + 1) == 'I') && (*(m + 2) == 'I') && (*(m + 3) == 'I') && (*(m + 4) == '\0')) //防止输出IIII表示4
	{ return 0;}

	while (*s != '\0') {
		p = s+1;
		if ((*s == 'I') && (*p == 'V'))
		{
			sum += 4;
			flag = 1;
		}
		else if ((*s == 'I') && (*p == 'X'))
		{
			sum += 9;
			flag = 1;
		}
		else if ((*s == 'X') && (*p == 'L'))
		{
			sum += 40;
			flag = 1;
		}
		else if ((*s == 'X') && (*p == 'C'))
		{
			sum += 90;
			flag = 1;
		}
		else if ((*s == 'C') && (*p == 'D'))
		{
			sum += 400;
			flag = 1;
		}
		else if ((*s == 'C') && (*p == 'M'))
		{
			sum += 900;
			flag = 1;
		}
		if (flag == 0)
		{
			if (*s == 'I') { sum += 1; }
			else if (*s == 'V') sum += 5;
			else if (*s == 'X') sum += 10;
			else if (*s == 'L') sum += 50;
			else if (*s == 'C') sum += 100;
			else if (*s == 'D') sum += 500;
			else if (*s == 'M') sum += 1000;
			s++;
		}
		else if (flag == 1)
			s += 2, flag = 0;
	}
	return sum;
}

int main()
{
	char s[] = "IIIIV";
	int sum = 0;
	sum = romanToInt(s);
	if(0 == sum)
		printf("输入错误\n");
	else printf("%d\n", sum);
	return 0;
}

