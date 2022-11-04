#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//14.编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。

//function:编写一个函数来查找字符串数组中的最长公共前缀
//传入参数：strs:二维数组的地址，即二级指针
//          strSize:传入比较的字符串个数。（之前一直没有理解这个是什么，一直以为是二维数组的元素个数，即占空间的大小）
//返回值：返回的是指针类型。注意的是返回的指针不要是函数内部定义的变量。会存在作用域的问题。

//本次的关注点有：1、二级指针怎么传参还不怎么会用；2、strs[0]得到的是一级指针，即地址。所以得到第一个字符串的第一个元素可以直接写成*（strs[0]）



char* longestCommonPrefix(char** strs, int strsSize) {
	int flag = 0;
	for (int i = 1; i < strsSize; i++)
	{
		for (int j = 0; (strs[0][j] != '\0'); j++)
		{
			if (strs[0][j] != strs[i][j])
			{
				flag = 1;
				strs[0][j] = '\0';
				break;
			}
		}
	}
	return strs[0];
}

int main(void)
{
	char* pc = NULL;
	char* pb[4] = {NULL};
	char strs[4][7] = { "flower","flower","flower","flower" };
//此处使用的是二级指针传参，首先要明白二级指针的含义：就是一级指针里面存放的元素还是地址，所以使用二级指针时，要把一级指针用上。
//                          再让一级指针里面存放地址，就好了。传进去的其实还是一级指针。只是里面放的是地址而已。
	pb[0] = strs[0];
	pb[1] = strs[1]; 
	pb[2] = strs[2];
	pb[3] = strs[3];
	pc = longestCommonPrefix(pb, 4);
	printf("%s", pc);
	return 0;
}