#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//14.��дһ�������������ַ��������е������ǰ׺����������ڹ���ǰ׺�����ؿ��ַ��� ""��

//function:��дһ�������������ַ��������е������ǰ׺
//���������strs:��ά����ĵ�ַ��������ָ��
//          strSize:����Ƚϵ��ַ�����������֮ǰһֱû����������ʲô��һֱ��Ϊ�Ƕ�ά�����Ԫ�ظ�������ռ�ռ�Ĵ�С��
//����ֵ�����ص���ָ�����͡�ע����Ƿ��ص�ָ�벻Ҫ�Ǻ����ڲ�����ı��������������������⡣

//���εĹ�ע���У�1������ָ����ô���λ�����ô���ã�2��strs[0]�õ�����һ��ָ�룬����ַ�����Եõ���һ���ַ����ĵ�һ��Ԫ�ؿ���ֱ��д��*��strs[0]��



char* longestCommonPrefix(char** strs, int strsSize) {
	int flag = 0;
	for (int i = 1; i < strsSize; i++)
	{
		for (int j = 0; (strs[0][j] != '\0'); j++)
		{
			if (strs[0][j] != strs[i][j])
			{
				flag = 1;
				strs[0][j] = '\0';
				break;
			}
		}
	}
	return strs[0];
}

int main(void)
{
	char* pc = NULL;
	char* pb[4] = {NULL};
	char strs[4][7] = { "flower","flower","flower","flower" };
//�˴�ʹ�õ��Ƕ���ָ�봫�Σ�����Ҫ���׶���ָ��ĺ��壺����һ��ָ�������ŵ�Ԫ�ػ��ǵ�ַ������ʹ�ö���ָ��ʱ��Ҫ��һ��ָ�����ϡ�
//                          ����һ��ָ�������ŵ�ַ���ͺ��ˡ�����ȥ����ʵ����һ��ָ�롣ֻ������ŵ��ǵ�ַ���ѡ�
	pb[0] = strs[0];
	pb[1] = strs[1]; 
	pb[2] = strs[2];
	pb[3] = strs[3];
	pc = longestCommonPrefix(pb, 4);
	printf("%s", pc);
	return 0;
}