#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>

//26. ɾ�����������е��ظ���
//function describle:����һ�� �������� ������ nums,����ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ��,
//                   ����ɾ����������³��ȡ�Ԫ�ص� ���˳�� Ӧ�ñ��� һ�¡�
//nums:����������ַ
//numsSize:�����Ԫ�ظ�����sizeof(arr)/sizeof(arr[0])
//return:�����в�ͬԪ�صĸ�����ͬʱ����Ƚϴ��������ǰ����Ԫ���Ƿ�ͬ��

//����������һ����ӵ����飬�˷�ʱ��Ϳռ䡣����������������������
//int removeDuplicates(int* nums, int numsSize) {
//	int* pb;
//	int j = 0;
//	int num = 1;
//	int flag = 0;
//	int i = 0;
//	pb = (int*)malloc(numsSize * sizeof(int));
//	pb = nums;
//	if (numsSize > 1)
//	{
//		for (i = 1; i < numsSize; i++)
//		{
//			if (*(nums + i - 1) != *(nums + i))
//			{
//				for (int j = 0; j < num; j++)
//				{
//					if (*(nums + i) == *(nums + j))
//					{
//						flag = 1;
//						break;
//					}
//				}
//				if (0 == flag)
//				{
//					pb++;
//					*pb = *(nums + i);
//					num++;
//				}
//			}
//			flag = 0;
//		}
//		for (j = 0; j < num; j++)
//		{
//			*(nums + j) = *(nums + j);
//			printf("%d\t", *(nums + j));
//		}
//		printf("\n");
//		return num;
//	}
//	else
//		return nums[numsSize - 1];
//}

//����ǲ����ö�������飬ֱ����ԭ�����ϸĽ���
int removeDuplicates(int* nums, int numsSize) {
	int j = 0;
	int i = 0;
	int flag = 0;
	if (numsSize > 1)
	{
		for (i = 0; i < numsSize; i++)
		{
			if (*(nums + j) != *(nums + i))
			{
				for (int k = 0; k < j + 1; k++)
				{
					if (*(nums + k) == *(nums + i))
					{
						flag = 1;
						break;
					}
				}
				if (0 == flag)
				{
					*(nums + j + 1) = *(nums + i);
					j++;
				}
			}
			flag = 0;
		}
		for (int a = 0; a < j + 1; a++)
		{
			printf("%d\t", nums[a]);
		}
		printf("\n");
		return ++j;
	}
	else
		return nums[numsSize - 1];
}


//����ǲ����ö�������飬ֱ����ԭ�����ϸĽ�������ֻ�����������������顣
//int removeDuplicates(int* nums, int numsSize) {
//	int j = 0;
//	int i = 0;
//	if (numsSize > 1)
//	{
//		for (i = 0; i < numsSize; i++)
//		{
//			if (*(nums + j) != *(nums + i))
//			{
//				*(nums + j + 1) = *(nums + i);
//				j++;
//			}
//		}
//		return ++j;
//	}
//	else
//		return nums[numsSize - 1];
//}


int main()
{
	int num = 0;
	int arr[] = {1,2,3,1,2,3,4,5,6};
	int numSize = sizeof(arr)/sizeof(arr[0]);
	printf("%d\n", numSize);
	num = removeDuplicates(arr, numSize);
	printf("%d", num);
	return 0;
}
