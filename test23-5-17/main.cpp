#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//�޸İ汾1.0��ֻ�������һλ��9�������û���뵽�����ڶ�λ����Ҳ��9�����������9,9�����

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
//�����һ��Ԫ�ؿ�ʼ������������digits�����ж��ٸ�9.
	int left = digitsSize - 1;   
//������ص������С����Ҫ��1�ǵ������С
	int add_size = digitsSize + 1; 
//int* arr_recive = digits������д�Ļ����ı���arr_reciveҲ�ͻ�һ��ĵ�digits���Ԫ�ء�
//                          �����Ͳ���ʹ��digits��
	int* arr_recive = NULL; 
//����forѭ��
	int i = 0;
//��ʼ��while�ң������￪ʼ����9
//�ر�ע�⣬����д�Ļ����ͻ������������ˣ���Ϊ��digits[-1]���������鷶Χ��LeetCode�ᱨ��
// 	        ÿ��д�����ʱ��Ҫע������ķ�Χ��vs���ᱨ������LeetCode�ᡣ
//while(9 == digits[left])
//{
//	left--;
//}
//���������break��
	while(9 == digits[left])
	{
		left--;
		if (-1 == left)
			break;
	}
	//���ȫ��9�Ļ���left == -1;
	if (-1 == left)
	{
		*returnSize = add_size;
		arr_recive = (int*)malloc(add_size * sizeof(int));
		//����c6011���棬ȡ����nullָ��arr_recive������
		if (NULL == arr_recive)
		{
			printf("arr_recive����ռ�ʧ��");
			exit(-1);
		}
		arr_recive[0] = 1;
		for (int j = 1; j < add_size; j++)
			*(arr_recive + j) = 0;
	}
	//��ȫ��9�ĵ�ʱ��
	else
	{
		*returnSize = digitsSize;
		arr_recive = (int*)malloc(digitsSize * sizeof(int));
		//����c6011���棬ȡ����nullָ��arr_recive������
		if (NULL == arr_recive)
		{
			printf("arr_recive����ռ�ʧ��");
			exit(-1);
		}
//�Ѳ���9���Ǹ�λ��1��ǰ��������ֲ��������
		for (i = 0; i < left; i++)
			*(arr_recive + i) = *(digits + i);
		*(arr_recive + left) = *(digits + left) + 1;
//���м���9��ʱ����Ҫ���������ȫ�����9
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
	int size = 0;//���ڴ�ŷ��ص�����Ĵ�С
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
	free(arr_test);//��Ϊ�Ƕ�̬������ڴ棬������Ҫ�ֶ��ͷ�

	return 0;
}




