#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

//function describle：给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//                    不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//                    元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//numsSize:数组的个数
//val:要删除的元素


//方法1：将val从非val开始往后放，对调两者的位置。但是感觉也不是很好
//int removeElement(int* nums, int numsSize, int val) {
//	int chang = 0;
//	int num = 0;
//	int j = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (*(nums + i) == val)
//		{
//			for (j = i; j < numsSize; j++)
//			{
//				if (*(nums + j) != val)
//				{
//					chang = *(nums + i);
//					*(nums + i) = *(nums + j);
//					*(nums + j) = chang;
//					num++;
//					break;
//				}
//			}
//			if (numsSize - 1 == j)
//				break;
//		}
//		else
//			num++;
//	}
//	//for (int k = 0; k < num; k++)
//	//{
//	//	printf("%d\t", nums[k]);
//	//}
//	//printf("\n");
//	return num;
//}


//方法二：看的别人的思路，之前也想到过用这个，但是没有想出来，可能是脑子没转过来
//        用一个变量来指定不是val的地方
//int removeElement(int* nums, int numsSize, int val) {
//	int k = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (*(nums + i) != val)
//		{
//			nums[k++] = *(nums + i);
//		}
//	}
//	return k;
//}

//方法三：把val往后放，但是和方法一差不多。都没有方法二好，之前怎么没有想到呢
int removeElement(int* nums, int numsSize, int val) {
	int chang = 0;
	int num = 0;
	int j = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (*(nums + i) == val)
		{
			for (j = numsSize-1; j >= i; j--)
			{
				if (*(nums + j) != val)
				{
					chang = *(nums + i);
					*(nums + i) = *(nums + j);
					*(nums + j) = chang;
					num++;
					break;
				}
			}
			if (i == j)
				break;
		}
		else
			num++;
	}
	//for (int k = 0; k < num; k++)
	//{
	//	printf("%d\t", nums[k]);
	//}
	//printf("\n");
	return num;
}

//方法四：我称之为最差劲的方法：就是利用第二个数组，将非val的元素搬到数组里面，然后再将第二个数组的元素放到原来数组里面





int main(void)
{
	int arr[] = { 1,2,3,1 };
	int get_num = 0;
	int arr_num = 0;

	arr_num = sizeof(arr) / sizeof(arr[0]);

	get_num = removeElement(arr, arr_num, 1);
	printf("%d", get_num);

	return 0;
}
