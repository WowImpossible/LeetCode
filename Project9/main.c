#define _CRT_SECURE_NO_WARNINGS 1

//��������ת���������13
//��ô˵�أ����ǰ����ļ��������������ٳ����Ϳ����ˣ��ͻ��ã����Ǻ��ѣ��������Python��˵����Լ�һ�㡣

#include <stdio.h>

//��Ŀ��������������ת������������ֻ��I�� V�� X�� L��C��D �� M�⼸�֣�����ת��Ϊ�����Ϳ����ˡ�
//���������s��Ҫת�����ַ���
//����ֵ������ֵ      
//�ɻ�ĵ㣬֮ǰ�����ڲ����õı���һ�������ͻᱻ���٣���������ȴû�б�����֪����ʲôԭ����û�п�������Ϊ����ֵ������
//          ����������ص��ǵ�ַ�Ļ��ͻᱨ�����Ƿ��ص�����ֵ�Ļ�Ӧ�ÿ��ԡ�������þ��ǲ�Ҫ����д�����淶��
//ע��ĵ㣺�������ǱȽϵ����ַ���˫�����Ǳ�ʾ�ַ�����


int romanToInt(char* s) {

	int sum = 0;
	char* p = s;
	char* m = s;
	int flag = 0;

	if ((*m == 'I') && (*(m + 1) == 'I') && (*(m + 2) == 'I') && (*(m + 3) == 'I') && (*(m + 4) == '\0')) //��ֹ���IIII��ʾ4
	{ return 0;}

	while (*s != '\0') {
		p = s+1;
		if ((*s == 'I') && (*p == 'V'))
		{
			sum += 4;
			flag = 1;
		}
		else if ((*s == 'I') && (*p == 'X'))
		{
			sum += 9;
			flag = 1;
		}
		else if ((*s == 'X') && (*p == 'L'))
		{
			sum += 40;
			flag = 1;
		}
		else if ((*s == 'X') && (*p == 'C'))
		{
			sum += 90;
			flag = 1;
		}
		else if ((*s == 'C') && (*p == 'D'))
		{
			sum += 400;
			flag = 1;
		}
		else if ((*s == 'C') && (*p == 'M'))
		{
			sum += 900;
			flag = 1;
		}
		if (flag == 0)
		{
			if (*s == 'I') { sum += 1; }
			else if (*s == 'V') sum += 5;
			else if (*s == 'X') sum += 10;
			else if (*s == 'L') sum += 50;
			else if (*s == 'C') sum += 100;
			else if (*s == 'D') sum += 500;
			else if (*s == 'M') sum += 1000;
			s++;
		}
		else if (flag == 1)
			s += 2, flag = 0;
	}
	return sum;
}

int main()
{
	char s[] = "IIIIV";
	int sum = 0;
	sum = romanToInt(s);
	if(0 == sum)
		printf("�������\n");
	else printf("%d\n", sum);
	return 0;
}

