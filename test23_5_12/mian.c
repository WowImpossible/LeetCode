#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//58��Length of Last Word
//Given a string s consisting of wordsand spaces, return the length of the last word in the string.
//A word is a maximal substring consisting of non - space characters only.

int lengthOfLastWord(char* s) {
	int count = 0;     //���ڼ�¼������ĸ�ĸ���
	while (*s != '\0') //�ַ���������\0��β��
	{
		//����⵽һ���ո�ʱ���Ƿ�Ҫ��count���㣬ȡ������һ���ַ���ʲô,�����\0�Ļ���count�Ͳ�������
		if ((*s == ' ') && (*(s+1) != '\0'))
		{
			//����������ǣ�����кü����ո�moon    \0�����ĸ��ո�,��ʱ���Ҫ�ѿո�ȫ�����յ���ָ����һ�����ǿո���ַ� 
			while (*(s + 1) == ' ')                  
				s++;
			if(*(s+1) != '\0')//ͬ��Ҫ�жϣ���һ���ַ���Ȼ���ǿո񣬿�����\0�������Ļ���count��ֵҲ��������
				count = 0;
		}
		else if(*s != ' ')//���ǿո�Ļ��Ϳ�ʼ��¼������
			count++;
		s++;//���Ҫ�ر�ע�⡣���++�Ļ�����������ѭ����
	}
	return count;
}



int main(void)
{
	char str[] = "   nihao a     ";
	int num;
	num = lengthOfLastWord(str);
	printf("%d\0", num);
	return 0;
}
