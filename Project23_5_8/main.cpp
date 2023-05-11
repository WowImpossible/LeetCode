#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//���ö��ֲ�����������ΪҪ��ʱ�临�ӶȲ��ܳ���log N
int searchInsert(int* nums, int numsSize, int target) {

	int right = 0;  //��¼�����ұߵ��±꣨��0��ͷ���Ķˣ�
	int left = numsSize - 1;  //��¼������ߵ��±�
	int middle = 0;  //��¼�м���Ǹ��±�

	//���ּ��˵����
	//1����ͷ�ж�����ͷ�ϵ��±��Ƿ��������Ҫ����±�
	//2����target��ֵ������������ֵ����ʱ����ʱ�ǿ���ֱ�ӷ��ص�\
	     ����˵��target��ֵ����������С��ֵ��Сʱ����ʱҲ�ǿ���ֱ�ӷ��ص�
	if (nums[right] >= target)
		return right;          //��������ķ���ֵ

	//���ܺ�����һ���ϲ���ԭ������Ϊ��target������ֵ����ʱ�����صĲ������һ��Ԫ�ص��±꣬���ǣ����һ��Ԫ��+1
	if (nums[left] = target)
		return left;           //��������ķ���ֵ�����ص����һ��Ԫ�ص��±꣬��ʱtarget�Ǵ����������е�
	else if (nums[left] < target)
		return left + 1;       //��������ķ���ֵ�����ص����һ��Ԫ�ص��±�+1����ʱtarget�ǲ������������е�


	//if (nums[right] > target)
	//	return right;
	//if (nums[left] < target)
	//	return left;


	//��ʼ��������
	while (right <= left)
	{
		middle = right + (left - right) / 2;  //��ʹ��(right+left)/2ʱ���ᷢ����������
		if (nums[middle] > target)            //��ʱ˵��Ŀ���������
			left = middle - 1;                //��Ϊ�����жϹ�nums[middle]����Ŀ����������left = middle - 1
		else if (nums[middle] < target)       //��ʱ˵��Ŀ�������ұ�
			right = middle + 1;
		else if (nums[middle] == target)
			return middle;                    //���ֲ����ҵ��ķ���ֵ
	}

	//����Ϊʲôд��������ʽ����������if������ΪLeetCode���汨��˵û�з���ֵ��
	if (nums[middle] < target) //���û��Ŀ����ʱ�����ֲ��ҿ����ҵ��Ǹ���Ӧ���Ǵ����Ǹ�λ��,��ʱ�����ж�\
		                         ���ص�ֵ���Ǵ�ʱ(middle)���±껹��middle+1���±ꡣ������ҵ������һ����\
		                         ��targetС����ʱ���ص�Ӧ����middle+1�������target�󣬷��صľ�Ӧ����middle��
		middle = middle + 1;

	return middle;//������Ҳ���ʱ���ص�ֵ
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