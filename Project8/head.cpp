#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "head.h"

/************************************************************************************************************
��������������һ������ x ����� x ��һ���������������� true �����򣬷��� false��
          ��������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������
          ���磬121 �ǻ��ģ��� 123 ���ǡ�
���������Ҫ�жϵ�����
����ֵ  ��bool����
ע���  ��ÿ����������֮�����¸����ֵ
************************************************************************************************************/

bool isPalindrome(int x) {
    int tmp = x;//���ڵõ�x�����ı�x��ֵ                 
    int recall_count = 0;//���ڼ�¼���ݵ�λ��
    int high = x;//���ڵõ����λ��ֵ
    int low = x;//����ÿ�ζ�����λ��õ�����
    int get_high = 0;//���ھ���ѭ���Ĵ��������Ƕ������ٸ����֣�
    int get_low = 0;//�õ�ÿ�ζ����λ֮�����µõ��µĸ�λ
    int count = 0;//���ڼ��㴫��������Ƕ���λ��    
    if (x < 0)
        return false;
    else
        do
        {
            tmp = tmp / 10;
            count++;
        } while (tmp != 0);
        recall_count = count;
        while (count != recall_count/2)//��Ϊ���������ǶԳƵģ����ԱȽ�һ��Ϳ�����
        {

            while (++get_high != count)
            {
                high = high / 10;
            }
            high = high % 10;
            get_low = low % 10;
            if (high != get_low)
                return false;
            high = x;
            count--;
            low = low / 10;
            get_high = 0;
        }
        return true;
}

