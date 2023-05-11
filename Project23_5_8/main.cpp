#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//采用二分查找来做，因为要求时间复杂度不能超过log N
int searchInsert(int* nums, int numsSize, int target) {

	int right = 0;  //记录数组右边的下标（从0开头的哪端）
	int left = numsSize - 1;  //记录数组左边的下标
	int middle = 0;  //记录中间的那个下标

	//两种极端的情况
	//1、开头判断两个头上的下标是否就是满足要求的下标
	//2、当target的值比数组中最大的值都大时，此时是可以直接返回的\
	     或者说，target的值比数组中最小的值都小时，此时也是可以直接返回的
	if (nums[right] >= target)
		return right;          //特殊情况的返回值

	//不能和上面一样合并的原因是因为当target比最大的值还大时，返回的不是最后一个元素的下标，而是，最后一个元素+1
	if (nums[left] = target)
		return left;           //特殊情况的返回值，返回的最后一个元素的下标，此时target是存在在数组中的
	else if (nums[left] < target)
		return left + 1;       //特殊情况的返回值，返回的最后一个元素的下标+1，此时target是不存在在数组中的


	//if (nums[right] > target)
	//	return right;
	//if (nums[left] < target)
	//	return left;


	//开始进入正文
	while (right <= left)
	{
		middle = right + (left - right) / 2;  //怕使用(right+left)/2时，会发生溢出的情况
		if (nums[middle] > target)            //此时说明目标数在左边
			left = middle - 1;                //因为下面判断过nums[middle]不是目标数，所以left = middle - 1
		else if (nums[middle] < target)       //此时说明目标数在右边
			right = middle + 1;
		else if (nums[middle] == target)
			return middle;                    //二分查找找到的返回值
	}

	//至于为什么写成这种形式，不用两个if，是因为LeetCode上面报错，说没有返回值。
	if (nums[middle] < target) //如果没有目标数时，二分查找可以找到那个数应该是处在那个位置,此时就是判断\
		                         返回的值，是此时(middle)的下标还是middle+1的下标。如果，找到的最后一个数\
		                         比target小，此时返回的应该是middle+1，如果比target大，返回的就应该是middle。
		middle = middle + 1;

	return middle;//这个是找不到时返回的值
}


int main(void)
{
	int arr[] = { 1,3,5,6 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	int target = 5;

	int num = 0;
	num = searchInsert(arr, arrSize, target);

	printf("%d\n", num);

	return 0;
}