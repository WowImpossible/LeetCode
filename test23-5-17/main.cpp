#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//修改版本1.0：只考虑最后一位是9的情况，没有想到倒数第二位可能也是9的情况，即：9,9的情况

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
//从最后一个元素开始遍历整个数组digits，找有多少个9.
	int left = digitsSize - 1;   
//如果返回的数组大小是需要加1是的数组大小
	int add_size = digitsSize + 1; 
//int* arr_recive = digits，这样写的话，改变了arr_recive也就会一起改掉digits里的元素。
//                          这样就不能使用digits了
	int* arr_recive = NULL; 
//用于for循环
	int i = 0;
//开始用while找，从哪里开始不是9
//特别注意，这样写的话，就会有数组的溢出了，因为，digits[-1]超出了数组范围，LeetCode会报错。
// 	        每次写数组的时候，要注意参数的范围。vs不会报错，但是LeetCode会。
//while(9 == digits[left])
//{
//	left--;
//}
//解决方法：break；
	while(9 == digits[left])
	{
		left--;
		if (-1 == left)
			break;
	}
	//如果全是9的话，left == -1;
	if (-1 == left)
	{
		*returnSize = add_size;
		arr_recive = (int*)malloc(add_size * sizeof(int));
		//消除c6011警告，取消对null指针arr_recive的引用
		if (NULL == arr_recive)
		{
			printf("arr_recive申请空间失败");
			exit(-1);
		}
		arr_recive[0] = 1;
		for (int j = 1; j < add_size; j++)
			*(arr_recive + j) = 0;
	}
	//不全是9的的时候
	else
	{
		*returnSize = digitsSize;
		arr_recive = (int*)malloc(digitsSize * sizeof(int));
		//消除c6011警告，取消对null指针arr_recive的引用
		if (NULL == arr_recive)
		{
			printf("arr_recive申请空间失败");
			exit(-1);
		}
//把不是9的那个位加1，前面的数保持不变存起来
		for (i = 0; i < left; i++)
			*(arr_recive + i) = *(digits + i);
		*(arr_recive + left) = *(digits + left) + 1;
//当中间是9的时候，需要将后面的数全部变成9
		if (digitsSize - 1 != left)
		{
			for (int j = left + 1; j < digitsSize; j++)
				*(arr_recive + j) = 0;
		}
	}
	return arr_recive;
}


int main(void)
{
	int size = 0;//用于存放返回的数组的大小
	int digits[] = { 9};
	int digitSize = sizeof(digits) / sizeof(digits[0]);
	int* returnSize = &size;
	int* arr_test = digits;
	int i = 0;
	arr_test = plusOne(digits, digitSize, returnSize);
	printf("%d\n", size);
	for (i = 0; i < size; i++ )
	{
		printf("%d\t", arr_test[i]);
	}
	free(arr_test);//因为是动态申请的内存，所以需要手动释放

	return 0;
}




