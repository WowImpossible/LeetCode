#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//#define search_num 8
//
//
//int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
//	int left = 0;
//	int right = numsSize - 1;
//	int middle = 0;
//	int arr[2] = { 0,0 };
//
//	if (nums == NULL)
//	{
//		arr[0] = -1;
//		arr[1] = -1;
//		returnSize = arr;
//		return returnSize;
//	}
//
//	if (nums[left] == target)
//	{
//		for (int i = 0; i < numsSize; )
//		{
//			if (nums[i] == target)
//				i++;
//			else
//			{
//				arr[0] = left;
//				arr[1] = i - 1;
//				returnSize = arr;
//				return returnSize;
//			}
//		}
//	}
//	if(nums[right] == target)
//	{
//		for (int i = numsSize - 1; i >= 0 ; )
//		{
//			if (nums[i] == target)
//				i--;
//			else
//			{
//				arr[1] = right;
//				arr[0] = i + 1;
//				returnSize = arr;
//				return returnSize;
//			}
//		}
//	}
//
//	while (left <= right)
//	{
//		middle = (left + right) / 2;
//		if (nums[middle] > target)
//		{
//			right = middle - 1;
//		}
//		else if(nums[middle] < target)
//		{
//			left = middle + 1;
//		}
//		else if(nums[middle] == target)
//		{
//			if ((nums[middle - 1] == target) && (nums[middle + 1] == target))
//			{
//				for (int i = 1; i < numsSize - middle ; )
//				{
//					if (nums[middle + i] == target)
//						i++;
//					else
//					{
//						arr[1] = middle + i - 1;
//					}
//				}
//				for (int i = 1; i < middle ; )
//				{
//					if (nums[middle - i] == target)
//						i++;
//					else
//					{
//						arr[0] = middle - i - 1;
//						returnSize = arr;
//						return returnSize;
//					}
//				}
//			}
//			else if ((nums[middle - 1] != target) && (nums[middle + 1] != target))
//			{
//				arr[0] = middle;
//				arr[1] = middle;
//				returnSize = arr;
//				return returnSize;
//			}
//			if (nums[middle + 1] == target)
//			{
//				if (nums[middle - 1] != target)
//				{
//					arr[0] = middle;
//					for (int i = 1; i < numsSize - middle ; )
//					{
//						if (nums[middle + i] == target)
//							i++;
//						else
//						{
//							arr[1] = middle + i - 1;
//							returnSize = arr;
//							return returnSize;
//						}
//					}
//				}
//			}
//			if (nums[middle - 1] == target)
//			{
//				if (nums[middle + 1] != target)
//				{
//					arr[1] = middle;
//					for (int i = 1; i <= middle ; )
//					{
//						if (nums[middle - i] == target)
//							i++;
//						else
//						{
//							arr[0] = middle - i + 1;
//							returnSize = arr;
//							return returnSize;
//						}
//					}
//				}
//			}
//		}
//	}
//	arr[0] = -1;
//	arr[1] = -1;
//	returnSize = arr;
//	return returnSize;
//}
//
//
//
//
//int main(void)
//{
//	//int arr[] = { 0, 1, 1, 2, 3, 4, 5, 5, 6, 6, 6, 6, 6 };
//	int arr[] = {5, 7, 7, 8, 8, 10};
//	int* receive = NULL;
//	int* returnSize = NULL;
//	int size = sizeof(arr) / sizeof(arr[0]);
//	receive = searchRange(arr, size, search_num, returnSize);
//	printf("%d %d\n", receive[0], receive[1]);
//
//	return 0;
//}

#include <stdio.h>
#include<stdlib.h>

//宏定义用于选择要查找的target
#define search_num 3

//34. Find First and Last Position of Element in Sorted Array
//Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

//If target is not found in the array, return[-1, -1].

//You must write an algorithm with O(log n) runtime complexity


int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int left = 0;
	int right = numsSize - 1;
	int middle = 0;
	int arr[2] = { 0,0 };

	if (nums == NULL)
	{
		returnSize[0] = -1;
		returnSize[1] = -1;
		//returnSize = arr;
		return returnSize;
	}

	if (nums[left] == target)
	{
		for (int i = 0; i < numsSize; )
		{
			if (nums[i] == target)
				i++;
			else
			{
				returnSize[0] = left;
				returnSize[1] = i - 1;
				//returnSize = arr;
				return returnSize;
			}
		}
	}
	if (nums[right] == target)
	{
		for (int i = numsSize - 1; i >= 0; )
		{
			if (nums[i] == target)
				i--;
			else
			{
				returnSize[1] = right;
				returnSize[0] = i + 1;
				//returnSize = arr;
				return returnSize;
			}
		}
	}

	while (left <= right)
	{
		middle = (left + right) / 2;
		if (nums[middle] > target)
		{
			right = middle - 1;
		}
		else if (nums[middle] < target)
		{
			left = middle + 1;
		}
		else if (nums[middle] == target)
		{
			if ((nums[middle - 1] == target) && (nums[middle + 1] == target))
			{
				for (int i = 1; i < numsSize - middle; )
				{
					if (nums[middle + i] == target)
						returnSize[1] = middle + i;
					else
						break;
					i++;
				}
				for (int i = 1; i < middle; )
				{
					if (nums[middle - i] == target)
						returnSize[0] = middle - i;
					else
						break;
					i++;
				}
				return returnSize;
			}
			else if ((nums[middle - 1] != target) && (nums[middle + 1] != target))
			{
				returnSize[0] = middle;
				returnSize[1] = middle;
				//returnSize = arr;
				return returnSize;
			}
			if (nums[middle + 1] == target)
			{
				if (nums[middle - 1] != target)
				{
					returnSize[0] = middle;
					for (int i = 1; i < numsSize - middle; )
					{
						if (nums[middle + i] == target)
							i++;
						else
						{
							returnSize[1] = middle + i - 1;
							//returnSize = arr;
							return returnSize;
						}
					}
				}
			}
			if (nums[middle - 1] == target)
			{
				if (nums[middle + 1] != target)
				{
					returnSize[1] = middle;
					for (int i = 1; i <= middle; )
					{
						if (nums[middle - i] == target)
							i++;
						else
						{
							returnSize[0] = middle - i + 1;
							//returnSize = arr;
							return returnSize;
						}
					}
				}
			}
		}
	}
	returnSize[0] = -1;
	returnSize[1] = -1;
	//returnSize = arr;
	return returnSize;
}

//int* searchRange1(int* nums, int numsSize, int target, int* returnSize) {
//	int* position;
//	int left, right, middle, i;
//	*returnSize = 2;
//	position = (int*)malloc(2 * sizeof(int));
//	if (numsSize == 0)
//	{
//		position[0] = position[1] = -1;
//		return position;
//	}
//	//寻找开始位置
//	position[0] = -1;
//	left = 0;
//	right = numsSize - 1;
//	while (left <= right)//左右闭区间，初始区间为[0,numsSize - 1]
//	{
//		middle = left + (right - left) / 2;//防止直接相加导致的int溢出
//		if (nums[middle] > target)
//			right = middle - 1;//左右闭区间[middle,right]全大于target，right修改为middle-1
//		else if (nums[middle] < target)
//			left = middle + 1;//左右闭区间[left,middle]全小于target，left修改为middle+1
//		else//middle == target
//		{
//			position[0] = middle;
//			right = middle - 1;//左右闭区间[middle,right]全大于等于target，为了找到开始位置，修改right
//		}
//	}
//	//寻找结束位置
//	if (position[0] == -1)//没有找到target
//	{
//		position[1] = -1;
//		return position;
//	}
//	for (position[1] = position[0]; position[1] < numsSize - 1; position[1]++)
//	{
//		if (nums[position[1] + 1] != target)
//			break;
//	}
//	return position;
//}




int main(void)
{
	//int arr[] = { 0, 1, 1, 2, 3, 4, 5, 5, 6, 6, 6, 6, 6 };
	int arr[] = { 1,2,3,3,3,3,4,5,9 };
	int* receive = NULL;
	int returnSize[2] = { 0 ,0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	receive = searchRange(arr, size, search_num, returnSize);
	printf("%d %d\n", receive[0], receive[1]);

	return 0;
}