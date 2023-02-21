#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

/*
指针方法
function discrible:Given an array of integers nums which is sorted in ascending order, and an integer target, 
                   write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
*/
int binary_search_1(int* num,int numsize,int target)
{
	int* left_point;
	int* right_point;
	int* half_point;
	int value = 0;
	left_point = num;
	right_point = num + numsize - 1;
	if (*(left_point) == target)
	{
		return 0;
	}
	else if(*(right_point) == target)
	{
		return numsize - 1;
	}


	while (left_point <= right_point)
	{
		half_point = left_point + (right_point - left_point)/2;
		value = *(half_point);
		if (value < target)
		{
			left_point = half_point + 1;
		}
		else if(value > target)
		{
			right_point = half_point - 1;
		}
		else if (value == target)
		{
			return (half_point - num);
		}
	}
	return -1;
}


//利用索引的方法
int binary_search_2(int* num, int numsize, int target)
{
	int left = 0;
	int right = numsize - 1;
	int middle = 0;

	if (num[left] == target)
	{
		return left;
	}
	else if (num[right] == target)
	{
		return right;
	}

	while (left <= right)
	{
		middle = (left + right) / 2;
		if (target == num[middle])//注意，此处，不能用target = num[middle]，这样的话相当于直接给target重新赋值，注意变量和常量的区别！
			return middle;
		else if (num[middle] > target)
			right = middle - 1;
		else if (num[middle] < target)
			left = middle + 1;
	}
	return -1;
}


int main()
{
	int index1;
	int index2;
	int arr[] = { -1,0,3,5,9,12 };
	int length = sizeof(arr) / sizeof(0);
	index1 = binary_search_1(arr, length, 2);
	index2 = binary_search_2(arr, length, 2);
	printf("%d\n", index1);
	printf("%d", index2);

	return 0;
}