#define _CRT_SECURE_NO_WARNINGS 1

//简单的一个返回两数之和为target的元素下标，很简单，不是很难

#include <stdio.h>
#include <string.h>



int* twoSum(int* nums, int numsSize, int target) {
	int flag = 0;
	int arr_ans[2] = {};
	int j;
	for (int i = 0; i < numsSize; i++)
	{
		for (j = i+1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			arr_ans[0] = i;
			arr_ans[1] = j;
			break;
		}
	}
	return arr_ans;
}


int main(void) {
	
	int* pc = NULL;
	int arr[5] = {1,2,2,4,3};
	int len = sizeof(arr);
	int target = 6;
	pc = twoSum(arr, len, target);
	printf("%d,%d", pc[0], pc[1]);
	return 0;
}

//2022年9月28日：判断一个字符串经过重组是否能和另外一个字符串相等

//bool CheckPermutation(char* s1, char* s2) {
//    int len1 = strlen(s1);
//    int len2 = strlen(s2);
//    int flage = 0;
//    if (len1 != len2)
//        return false;
//    else
//    {
//        for (int i = 0; i < len1; i++)
//        {
//            for (int j = 0; j < len1; j++)
//            {
//                if (s1[i] == s2[j])
//                {
//                    s2[j] = ' ';
//                    break;
//                }
//            }
//        }
//        for (int i = 0; i < len1;i++)
//        {
//            if (s2[i] == ' ')
//                flage++;
//        }
//        if (flage == len1)
//            return true;
//        else
//            return false;
//    }
//}
//
//
//int main(void)
//{
//    char s1[] = "abb";
//    char s2[] = "aab";
//    printf("%d", CheckPermutation(s1, s2));
//
//    return 0;
//}


//int CheckPermutation(int* s1, int* s2) {
//	int length = sizeof(s1)/sizeof(s1[0]);
//	return length;
//}
//
//
//int main(void)
//{
//	int arr[7] = { 1,2,3,4,5 };
//	int arr1[7] = { 1,2,3,4,5 };
//	int ni = sizeof(arr)/sizeof(arr[1]);
//	printf("%d\n",ni);
//	printf("%d", CheckPermutation(arr, arr1));
//	return 0;
//}

