#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>

//26. 删除有序数组中的重复项
//function describle:给你一个 升序排列 的数组 nums,请你原地删除重复出现的元素，使每个元素 只出现一次,
//                   返回删除后数组的新长度。元素的 相对顺序 应该保持 一致。
//nums:传入的数组地址
//numsSize:数组的元素个数：sizeof(arr)/sizeof(arr[0])
//return:数组中不同元素的个数。同时还会比较传入数组的前几个元素是否不同。

//这里是用了一个外加的数组，浪费时间和空间。但是这个可以排乱序的数组
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

//这个是不适用额外的数组，直接在原数组上改进。
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


//这个是不适用额外的数组，直接在原数组上改进。但是只是针对升序排序的数组。
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
