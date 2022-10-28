#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "head.h"

/************************************************************************************************************
函数描述：给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false。
          回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
          例如，121 是回文，而 123 不是。
传入参数：要判断的数字
返回值  ：bool类型
注意点  ：每个变量用完之后重新赋予的值
************************************************************************************************************/

bool isPalindrome(int x) {
    int tmp = x;//用于得到x而不改变x的值                 
    int recall_count = 0;//用于记录数据的位数
    int high = x;//用于得到最高位的值
    int low = x;//用于每次丢到个位后得到的数
    int get_high = 0;//用于决定循环的次数（就是丢掉多少个数字）
    int get_low = 0;//得到每次丢完个位之后重新得到新的个位
    int count = 0;//用于计算传入的数据是多少位的    
    if (x < 0)
        return false;
    else
        do
        {
            tmp = tmp / 10;
            count++;
        } while (tmp != 0);
        recall_count = count;
        while (count != recall_count/2)//因为回文数都是对称的，所以比较一半就可以了
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

